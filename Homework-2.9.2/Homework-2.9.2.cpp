#include <iostream>
#include <string>

class Fraction {
private:
    int numerator_;
    int denominator_;

public:
    Fraction(int numerator, int denominator) {
        numerator_ = numerator;
        denominator_ = denominator;
    }

    Fraction operator+(Fraction other) {
        if (denominator_ == other.denominator_) {

            return Fraction((numerator_ + other.numerator_), denominator_);
        }
        else {
            return  Fraction((numerator_ * other.denominator_ +
                denominator_ * other.numerator_),
                (denominator_ * other.denominator_));
        }
    }
    Fraction operator-(Fraction other) {
        if (denominator_ == other.denominator_) {
            return Fraction((numerator_ - other.numerator_), denominator_);
        }
        else {
            return Fraction((numerator_ * other.denominator_ -
                denominator_ * other.numerator_),
                (denominator_ * other.denominator_));
        }
    }
    Fraction operator*(Fraction other) {
        return (Fraction((numerator_ * other.numerator_),
            (denominator_ * other.denominator_)));
    }
    Fraction operator/(Fraction other) {
        return (Fraction((numerator_ * other.denominator_),
            (denominator_ * other.numerator_)));
    }

    Fraction operator-() { return Fraction(-numerator_, denominator_); }
    Fraction operator++() {
        numerator_ += denominator_;
        return *this;
    }
    Fraction operator++(int) {
        Fraction temp = *this;
        ++(*this);
        return temp;
    }
    Fraction operator--() {
        numerator_ -= denominator_;
        return *this;
    }
    Fraction operator--(int) {
        Fraction temp = *this;
        --(*this);
        return temp;
    }

    void print() { std::cout << numerator_ << "/" << denominator_ << std::endl; }
};

int main() {
    setlocale(LC_ALL, "Russian");

    int numerator1, denominator1;
    int numerator2, denominator2;

    std::cout << "¬ведите числитель дроби 1: ";
    std::cin >> numerator1;
    std::cout << "¬ведите знаменатель дроби 1: ";
    std::cin >> denominator1;
    std::cout << "¬ведите числитель дроби 2: ";
    std::cin >> numerator2;
    std::cout << "¬ведите знаменатель дроби 2: ";
    std::cin >> denominator2;

    Fraction f1(numerator1, denominator1);
    Fraction f2(numerator2, denominator2);

    Fraction sum = f1 + f2;
    Fraction sub = f1 - f2;
    Fraction mult = f1 * f2;
    Fraction divide = f1 / f2;

    std::cout << numerator1 << "/" << denominator1 << " + " << numerator2 << "/"
        << denominator2 << " = ";
    sum.print();
    std::cout << numerator1 << "/" << denominator1 << " - " << numerator2 << "/"
        << denominator2 << " = ";
    sub.print();
    std::cout << numerator1 << "/" << denominator1 << " * " << numerator2 << "/"
        << denominator2 << " = ";
    mult.print();
    std::cout << numerator1 << "/" << denominator1 << " / " << numerator2 << "/"
        << denominator2 << " = ";
    divide.print();

    Fraction increment_mult = ++f1 * f2;
    Fraction increment = ++f1;

    std::cout << "++" << numerator1 << "/" << denominator1 << " * " << numerator2
        << "/" << denominator2 << " = ";
    increment_mult.print();
    std::cout << "«начение дроби 1: ";
    increment.print();

    Fraction decrement_mult = f1-- * f2;
    Fraction decrement = f1--;

    std::cout << numerator1 << "/" << denominator1 << "--"
        << " * " << numerator2 << "/" << denominator2 << " = ";
    decrement_mult.print();
    std::cout << "«начение дроби 1: ";
    decrement.print();
}
