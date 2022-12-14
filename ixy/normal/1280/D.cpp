#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 3e3 + 5;

int n, m, a[N], siz[N], f[N][N];
long long g[N][N];
std::vector<int> e[N];

void dfs(int u, int fa) {
    siz[u] = 1;
    for (int i = 0; i <= m; i++) { f[u][i] = 0; g[u][i] = -1e18; }
    f[u][0] = 0; g[u][0] = 0;
    for (auto v : e[u]) {
        if (v != fa) {
            dfs(v, u);
            for (int i = std::min(m, siz[u] + siz[v]); i >= 0; i--) {
                int _f = 0; long long _g = -1e18;
                for (int j = std::max(0, i - siz[u]); j <= i && j <= siz[v]; j++) {
                    if (_f < f[v][j] + f[u][i - j]) {
                        _f = f[v][j] + f[u][i - j]; _g = g[v][j] + g[u][i - j];
                    } else if (_f == f[v][j] + f[u][i - j]) {
                        _g = std::max(_g, g[v][j] + g[u][i - j]);
                    }
                }
                f[u][i] = _f; g[u][i] = _g;
            }
            siz[u] += siz[v];
        }
    }
    for (int i = m; i >= 0; i--) {
        if (i == 0) {
            g[u][i] += a[u];
        } else if (u == 1) {
            f[u][i] = f[u][i - 1] + (int) (g[u][i - 1] + a[u] > 0); g[u][i] = 0;
        } else if (f[u][i] < f[u][i - 1] + (int) (g[u][i - 1] + a[u] > 0)) {
            f[u][i] = f[u][i - 1] + (int) (g[u][i - 1] + a[u] > 0); g[u][i] = 0;
        } else if (f[u][i] == f[u][i - 1] + (int) (g[u][i - 1] + a[u] > 0)) {
            g[u][i] = std::max(g[u][i] + a[u], 0ll);
        } else {
            g[u][i] += a[u];
        }
    }
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); m = read();
        for (int u = 1; u <= n; u++) { e[u].clear(); }
        for (int u = 1; u <= n; u++) { a[u] = -read(); }
        for (int u = 1; u <= n; u++) { a[u] += read(); }
        for (int i = 2; i <= n; i++) {
            int u = read(), v = read();
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1, 0);
        printf("%d\n", f[1][m]);
    }
    return 0;
}