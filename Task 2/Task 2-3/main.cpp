﻿#include <iostream>

/**
 * \brief Считывает натуральное число из консоли.
 * \param message Мотивационное сообщение для пользователя.
 * \return Натуральное число.
 */
int read_number(const std::string& message);

/**
 * \brief Функция сортировки по возрастанию трех чисел.
 * \param a первое число.
 * \param b второе число.
 * \param c третье число.
 * \return 0 в случае успеха.
 */
int ascendingSort(double &a, double &b, double &c);

/**
 * \brief Функция сортировки по возрастанию двух чисел.
 * \param a первое число.
 * \param b второе число.
 * \return 0 в случае успеха.
 */
int ascendingSort(double &a, double &b);

/**
 * \brief Функция нахождения минимального из трех чисел.
 * \param a первое число.
 * \param b второе число.
 * \param c третье число.
 * \return минимальное из трех чисел.
 */
double getMinimum(double a, double b, double c);

/**
 * \brief Функция нахождения максимального из трех чисел.
 * \param a первое число.
 * \param b второе число.
 * \param c третье число.
 * \return максимальное из трех чисел.
 */
double getMaximum(double a, double b, double c);

/**
 * \brief Узнает, существует ли логарифм в заданной точке \a x.
 * \param x Заданная точка.
 * \return true, если значение логарифма в заданной точке \a x существует.
 */
bool isCalculated(double x);

/**
 * \brief Точка входа в программу.
 * \return 0 в случае успеха.
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    try
    {
        const auto NUMBER = read_number("Введите число ");
        double sine = sin(NUMBER);
        std::cout << "Синус числа равен " << sine << "\n";
        double cosine = cos(NUMBER);
        std::cout << "Косинус числа равен " << cosine << "\n";
        if (isCalculated(NUMBER)) {
            double logarithm = log(NUMBER);
            std::cout << "Логарифм числа равен " << logarithm << "\n";
            ascendingSort(sine, cosine, logarithm);
            std::cout << sine << " " << cosine << " " << logarithm << std::endl;
        }
        else {
            std::cout << "Логарифм не вычисляется" << "\n";
            ascendingSort(sine, cosine);
            std::cout << sine << " " << cosine << std::endl;
        }
        return 0;
    }
    catch (...)
    {
        return 1;
    }
}

double getMinimum(double a, double b, double c)
{
    if (a > b) a = b;
    if (a > c) a = c;
    return a;
}

double getMaximum(double a, double b, double c)
{
    if (a < b) a = b;
    if (a < c) a = c;
    return a;
}

int ascendingSort(double &a, double &b, double &c)
{
    
    const double summ = a + b + c;
    const double min = getMinimum(a, b, c);
    const double max = getMaximum(a, b, c);
    a = min;
    c = max;
    b = summ - a - c;
    return 0;
}

int ascendingSort(double &a, double &b)
{
    if (a > b) {
        double auxiliary = a;
        a = b;
        b = auxiliary;
    }
    return 0;
}

int read_number(const std::string& message)
{
    std::cout << message;
    int number = 0;
    std::cin >> number;
    return number;
}

bool isCalculated(const double x)
{
    return x > 0;
}
