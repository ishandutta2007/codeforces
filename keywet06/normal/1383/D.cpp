#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) std::cin >> a[i][j], a[i][j]--;
    }
    std::vector<int> rMax(n * m), cMax(n * m);
    for (int i = 0; i < n; ++i) {
        int mx = 0;
        for (int j = 0; j < m; ++j) mx = std::max(mx, a[i][j]);
        rMax[mx] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int mx = 0;
        for (int j = 0; j < n; ++j) mx = std::max(mx, a[j][i]);
        cMax[mx] = 1;
    }
    std::vector<int> px(n * m), py(n * m);
    int x = -1, y = -1;
    for (int i = n * m - 1; i >= 0; --i) {
        if (cMax[i] || rMax[i]) {
            if (rMax[i]) ++x;
            if (cMax[i]) ++y;
            a[x][y] = i;
            px[i] = x;
            py[i] = y;
        }
    }
    int cur = 0;
    for (int i = 0; i < n * m; ++i) {
        if (rMax[i]) {
            for (int y = 0; y < py[i]; ++y) {
                while (rMax[cur] || cMax[cur]) ++cur;
                a[px[i]][y] = cur++;
            }
        }
        if (cMax[i]) {
            for (int x = 0; x < px[i]; ++x) {
                while (rMax[cur] || cMax[cur]) ++cur;
                a[x][py[i]] = cur++;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << a[i][j] + 1 << " \n"[j == m - 1];
        }
    }
    return 0;
}