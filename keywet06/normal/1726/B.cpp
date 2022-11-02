#include <bits/stdc++.h>

int T, n, m;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        if (m < n) {
            std::cout << "No" << '\n';
        } else if (n == 1) {
            std::cout << "Yes" << '\n';
            std::cout << m << '\n';
        } else if (n == 2) {
            if (m & 1) {
                std::cout << "No" << '\n';
            } else {
                std::cout << "Yes" << '\n';
                std::cout << m / 2 << ' ' << m / 2 << '\n';
            }
        } else {
            if (n & 1) {
                std::cout << "Yes" << '\n';
                for (int i = 1; i < n; ++i) std::cout << "1 ";
                std::cout << m - (n - 1) << '\n';
            } else if (m & 1) {
                std::cout << "No" << '\n';
            } else {
                std::cout << "Yes" << '\n';
                for (int i = 1; i < n - 1; ++i) std::cout << "1 ";
                std::cout << (m - (n - 2)) / 2 << ' ' << (m - (n - 2)) / 2 << '\n';
            }
        }
    }
    return 0;
}