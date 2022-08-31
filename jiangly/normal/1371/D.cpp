#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::cout << (k % n == 0 ? 0 : 2) << "\n";
        std::vector<std::vector<int>> a(n, std::vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (k > 0)
                    a[j][(i + j) % n] = 1, --k;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                std::cout << a[i][j];
            std::cout << "\n";
        }
    }
    return 0;
}