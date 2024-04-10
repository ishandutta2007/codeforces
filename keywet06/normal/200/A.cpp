#include <bits/stdc++.h>

int n, m, T, x, y, a, b;
int d[2010][2010], v[2010][2010];

bool solve(int x, int y, int k) {
    int l = std::max(1, x - k), r = std::min(x + k, n), t;
    for (int i = l; i <= r; ++i) {
        t = k - std::abs(i - x);
        if (y - t > 0 && !v[i][y - t]) return a = i, b = y - t, 1;
        if (y + t <= m && !v[i][y + t]) return a = i, b = y + t, 1;
    }
    return 0;
}
int main() {
    std::cin >> n >> m >> T;
    while (T--) {
        std::cin >> x >> y;
        for (int i = -2; i <= 2; ++i) {
            for (int j = -2; j <= 2; ++j) {
                if (x + i < 1 || x + i > n || y + j < 1 || y + j > m) continue;
                d[x][y] = std::max(d[x][y],
                                   d[x + i][y + j] - std::abs(i) - std::abs(j));
            }
        }
        while (!solve(x, y, d[x][y])) ++d[x][y];
        std::cout << a << ' ' << b << '\n', v[a][b] = 1;
    }
    return 0;
}