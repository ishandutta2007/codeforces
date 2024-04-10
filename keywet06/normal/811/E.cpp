#include <bits/stdc++.h>

const int N = 12;
const int M = 100002;
const int K = N * M;

int n, m, k, q;
int px[K], py[K], vis[K];
int a[N][M], f[N][M], v[N][M], ex[N][M], ey[N][M];

void dfs(int x, int y) {
    f[x][y] = k;
    for (int i = 0; i < 2; ++i) {
        int xx = x + 1 - 2 * i, yy = y + 1 - 2 * i;
        if (ex[x][y - i] && !~f[x][yy]) dfs(x, yy);
        if (ey[x - i][y] && !~f[xx][y]) dfs(xx, y);
    }
}

int ff(int s[N][M], int x, int y, int xx, int yy) {
    return x > xx || y > yy ? 0 : s[xx][yy] - s[x - 1][yy] - s[xx][y - 1] + s[x - 1][y - 1];
}

bool wrk(int z, int x, int y, int xx, int yy) {
    return !vis[z] && px[z] >= x && px[z] <= xx && py[z] >= y && py[z] <= yy;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) std::cin >> a[i][j];
    }
    for (int i = 1; i <= n + 1; ++i) {
        for (int j = 1; j <= m + 1; ++j) {
            f[i][j] = -1;
            ex[i][j] = a[i][j] != a[i - 1][j];
            ey[i][j] = a[i][j] != a[i][j - 1];
        }
    }
    for (int i = 1; i <= n + 1; ++i) {
        for (int j = 1; j <= m + 1; ++j) {
            if (!~f[i][j]) v[px[k] = i][py[k] = j] = 1, dfs(i, j), k++;
        }
    }
    for (int i = 1; i <= n + 1; ++i) {
        for (int j = 1; j <= m + 1; ++j) {
            v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
            ex[i][j] += ex[i - 1][j] + ex[i][j - 1] - ex[i - 1][j - 1];
            ey[i][j] += ey[i - 1][j] + ey[i][j - 1] - ey[i - 1][j - 1];
        }
    }
    while (q--) {
        int x = 1, y, xx = n, yy;
        std::cin >> y >> yy;
        int dx = xx - x + 1, dy = yy - y + 1;
        int ret = ff(ex, x + 1, y, xx, yy) + ff(ey, x, y + 1, xx, yy) + ff(v, x + 1, y + 1, xx, yy) + 2 * (dx + dy) +
                  1 - (dx + 1) * (dy + 1);
        for (int i = x; i <= xx + 1; ++i) {
            if (wrk(f[i][y], x + 1, y + 1, xx, yy)) vis[f[i][y]] = 1, --ret;
            if (wrk(f[i][yy + 1], x + 1, y + 1, xx, yy)) vis[f[i][yy + 1]] = 1, --ret;
        }
        for (int i = x; i <= xx + 1; ++i) vis[f[i][y]] = vis[f[i][yy + 1]] = 0;
        std::cout << ret << '\n';
    }
    return 0;
}