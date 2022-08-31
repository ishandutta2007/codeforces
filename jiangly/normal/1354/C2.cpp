#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <iomanip>
constexpr double Pi = std::atan2(0, -1);
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    std::cout << std::fixed << std::setprecision(10);
    while (t--) {
        int n;
        std::cin >> n;
        if (n % 2 == 0) {
            std::cout << 1 / std::tan(Pi / (2 * n)) << "\n";
        } else {
            std::cout << 0.5 / std::sin(Pi / (4 * n)) << "\n";
        }
    }
    return 0;
}