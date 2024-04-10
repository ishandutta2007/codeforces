#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long u, v;
    std::cin >> u >> v;
    if (u > v || u % 2 != v % 2) {
        std::cout << -1 << "\n";
    } else if (u == 0 && v == 0) {
        std::cout << 0 << "\n";
    } else if (u == v) {
        std::cout << 1 << "\n";
        std::cout << u << "\n";
    } else {
        long long w = (v - u) / 2;
        if ((u & w) == 0) {
            std::cout << 2 << "\n";
            std::cout << u + w << " " << w << "\n";
        } else {
            std::cout << 3 << "\n";
            std::cout << u << " " << w << " " << w << "\n";
        }
    }
    return 0;
}