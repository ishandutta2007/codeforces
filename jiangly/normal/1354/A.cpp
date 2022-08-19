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
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        if (a <= b) {
            std::cout << b << "\n";
        } else if (d >= c) {
            std::cout << -1 << "\n";
        } else {
            a -= b;
            int t = (a + c - d - 1) / (c - d);
            std::cout << b + 1ll * c * t << "\n";
        }
    }
    return 0;
}