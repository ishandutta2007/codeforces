#include <bits/stdc++.h>

int T, n, x;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> x;
        n /= 2;
        std::cout << n * 6 << std::endl;
        for (int i = 1; i <= n; ++i) {
            std::cout << "1 " << 2 * i - 1 << " " << 2 * i << std::endl;
            std::cout << "2 " << 2 * i - 1 << " " << 2 * i << std::endl;
            std::cout << "1 " << 2 * i - 1 << " " << 2 * i << std::endl;
            std::cout << "1 " << 2 * i - 1 << " " << 2 * i << std::endl;
            std::cout << "2 " << 2 * i - 1 << " " << 2 * i << std::endl;
            std::cout << "1 " << 2 * i - 1 << " " << 2 * i << std::endl;
        }
    }
    return 0;
}