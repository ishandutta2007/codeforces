#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;
    --x;
    --y;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i % 2 == 0) {
                std::cout << (x + i) % n + 1 << " " << (y + j) % m + 1 << "\n";
            } else {
                std::cout << (x + i) % n + 1 << " " << (y + m - j - 1) % m + 1 << "\n";
            }
        }
    }
    return 0;
}