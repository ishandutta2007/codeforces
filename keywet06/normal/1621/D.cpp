#include <bits/stdc++.h>

using int64 = long long;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        int m = n << 1;
        std::vector<std::vector<int> > a(m, std::vector<int>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) std::cin >> a[i][j];
        }
        int64 Ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) Ans += a[i][j] + a[n + i][n + j];
        }
        int Min = 1e9;
        Min = std::min(Min, a[0][n]);
        Min = std::min(Min, a[0][m - 1]);
        Min = std::min(Min, a[n - 1][n]);
        Min = std::min(Min, a[n - 1][m - 1]);
        Min = std::min(Min, a[n][0]);
        Min = std::min(Min, a[n][n - 1]);
        Min = std::min(Min, a[m - 1][0]);
        Min = std::min(Min, a[m - 1][n - 1]);
        std::cout << (Ans += Min) << '\n';
    }
    return 0;
}