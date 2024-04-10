#include <bits/stdc++.h>

using int64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> cnt(n * n);
    std::vector a(n, std::vector<int>(n));
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) std::cin >> a[i][j], --a[i][j], cur += !cnt[a[i][j]]++;
    }
    if (k >= cur) return std::cout << k - cur << "\n", 0;
    std::vector<int> Xm(n * n, n), Xx(n * n, -1);
    std::vector<int> Ym(n * n, n), Yx(n * n, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x = a[i][j];
            Xm[x] = std::min(Xm[x], i);
            Xx[x] = std::max(Xx[x], i);
            Ym[x] = std::min(Ym[x], j);
            Yx[x] = std::max(Yx[x], j);
        }
    }
    for (int d = 1; d <= n; ++d) {
        std::vector a(n - d + 1, std::vector<int>(n - d + 1));
        for (int x = 0; x < n * n; ++x) {
            if (Xm[x] == n) continue;
            ++a[0][0];
            int x1 = std::max(Xx[x] - d + 1, 0), x2 = std::min(Xm[x], n - d);
            int y1 = std::max(Yx[x] - d + 1, 0), y2 = std::min(Ym[x], n - d);
            if (x1 <= x2 && y1 <= y2) {
                --a[x1][y1];
                if (y2 < n - d) ++a[x1][y2 + 1];
                if (x2 < n - d) ++a[x2 + 1][y1];
                if (x2 < n - d && y2 < n - d) --a[x2 + 1][y2 + 1];
            }
        }
        for (int i = 0; i < n - d + 1; ++i) {
            for (int j = 1; j < n - d + 1; ++j) a[i][j] += a[i][j - 1];
        }
        for (int i = 1; i < n - d + 1; ++i) {
            for (int j = 0; j < n - d + 1; ++j) a[i][j] += a[i - 1][j];
        }
        for (int i = 0; i < n - d + 1; ++i) {
            for (int j = 0; j < n - d + 1; ++j) {
                if (a[i][j] == k || a[i][j] == k - 1) return std::cout << 1 << "\n", 0;
            }
        }
    }
    std::cout << 2 << "\n";
    return 0;
}