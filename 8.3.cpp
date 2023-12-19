#include <iostream>
#include <vector>

class Person {
private:
    int age;

public:
    Person(int age) : age(age) {}

    int getAge() const {
        return age;
    }
};

class Car {
private:
    int manufacturingYear;

public:
    Car(int year) : manufacturingYear(year) {}

    // For illustration purposes, using the manufacturing year as a representation of age
    int getAge() const {
        // Assuming the current year is 2023
        return 2023 - manufacturingYear;
    }
};

template <typename T>
class AverageAgeCalculator {
private:
    std::vector<T> objects;

public:
    void addObject(const T& object) {
        objects.push_back(object);
    }

    double computeAverageAge() const {
        if (objects.empty()) {
            return 0.0; // Avoid division by zero
        }

        double totalAge = 0.0;
        for (const auto& obj : objects) {
            totalAge += obj.getAge();
        }

        return totalAge / objects.size();
    }
};

int main() {
    // Create an AverageAgeCalculator for persons
    AverageAgeCalculator<Person> personAgeCalculator;

    // Add persons to the list
    personAgeCalculator.addObject(Person(25));
    personAgeCalculator.addObject(Person(30));

    // Compute and display the average age of persons
    std::cout << "Average Age of Persons: " << personAgeCalculator.computeAverageAge() << " years\n";

    // Create an AverageAgeCalculator for cars
    AverageAgeCalculator<Car> carAgeCalculator;

    // Add cars to the list
    carAgeCalculator.addObject(Car(2018));
    carAgeCalculator.addObject(Car(2015));

    // Compute and display the average age of cars
    std::cout << "Average Age of Cars: " << carAgeCalculator.computeAverageAge() << " years\n";

    return 0;
}
