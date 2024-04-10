#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int a, b;
        std::cin >> a >> b;
        if (a > b)
            std::swap(a, b);
        if (b >= 2 * a) {
            std::cout << a << "\n";
        } else {
            std::cout << (a + b) / 3 << "\n";
        }
    }
    return 0;
}