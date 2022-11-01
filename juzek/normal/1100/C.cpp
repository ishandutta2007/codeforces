#include <cstdio>
#include <cmath>

int main() {
    double N, R;
    scanf("%lf%lf", &N, &R);
    double a = 2 * 3.14159265358979323846264338327950288 / N;
    double s = std::sin(a / 2);
    double x = R * s / (1 - s);
    printf("%.8lf", x);
    return 0;
}