#include <bits/stdc++.h>

int T, n;

int main() {
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        if (n % 2 == 0) {
            for (int i = 1; i <= n / 2; ++i) {
                std::cout << i * 2 << ' ' << i * 2 - 1 << ' ';
            }
            std::cout << std::endl;
        } else {
            for (int i = 1; i < n / 2; ++i) {
                std::cout << i * 2 << ' ' << i * 2 - 1 << ' ';
            }
            std::cout << n - 1 << ' ' << n << ' ' << n - 2 << std::endl;
        }
    }
    return 0;
}