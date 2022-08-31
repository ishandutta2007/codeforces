#include <iostream>
long long t, n, g, b;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--) {
        std::cin >> n >> g >> b;
        auto h = (n + 1) / 2;
        std::cout << std::max(n, h + (h - 1) / g * b) << "\n";
    }
    return 0;
}