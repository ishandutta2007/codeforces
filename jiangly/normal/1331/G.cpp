// luogu
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
double f(double t) {
    return std::sqrt(std::abs(t)) + 5 * std::pow(t, 3);
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a[11];
    for (int i = 0; i < 11; ++i)
        std::cin >> a[i];
    std::cout << std::fixed << std::setprecision(2);
    for (int i = 10; i >= 0; --i) {
        auto y = f(a[i]);
        std::cout << "f(" << a[i] << ") = ";
        if (y > 400) {
            std::cout << "MAGNA NIMIS!\n";
        } else {
            std::cout << y << "\n";
        }
    }
    return 0;
}