#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n, k;
        std::cin >> n >> k;
        if (k * 2 - 1 > n) {
            std::cout << -1 << std::endl;
            continue;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << (i == j && !(i & 1) && i < 2 * k ? 'R' : '.');
            }
            std::cout << std::endl;
        }
    }
    return 0;
}