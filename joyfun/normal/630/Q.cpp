#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);

typedef long long ll;

double x;

double gao1() {
    scanf("%lf", &x);
    return sqrt(2) * x * x * x / 12;
}

double gao2() {
    scanf("%lf", &x);
    return sqrt(2) * x * x * x / 6;
}

double get(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double gao3() {
    double a;
    scanf("%lf", &a);
    double b = a / sin(2.0 / 5 * pi) * sin(3.0 / 10 * pi);
    double h = sqrt(a * a - b * b);
    return h * get(a, b, b) * 5 / 3;
}

int main() {
    printf("%.100f\n", gao1() + gao2() + gao3());
    return 0;
}