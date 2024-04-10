#include <bits/stdc++.h>

inline void Solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector Adj(n, std::vector(n, -1));
    std::vector<std::vector<int>> f;
    std::vector<int> g, Col(m);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        std::cin >> a >> b >> c, --a, --b, c -= c > 0;
        Adj[a][b] = Adj[b][a] = i;
        if (c != -1) f.emplace_back(m), f.back()[i] = 1, g.push_back(c);
    }
    for (int a = 0; a < n; ++a) {
        for (int b = a + 1; b < n; ++b) {
            if (Adj[a][b] == -1) continue;
            for (int c = b + 1; c < n; ++c) {
                if (Adj[a][c] == -1 || Adj[b][c] == -1) continue;
                f.emplace_back(m);
                f.back()[Adj[a][b]] = f.back()[Adj[b][c]] = f.back()[Adj[a][c]] = 1;
                g.push_back(0);
            }
        }
    }
    const int r = f.size();
    int Rank = 0;
    for (int i = 0; i < m; ++i) {
        int j = Rank;
        while (j < r && f[j][i] == 0) ++j;
        if (j == r) continue;
        std::swap(f[j], f[Rank]);
        std::swap(g[j], g[Rank]);
        j = Rank++;
        if (f[j][i] == 2) {
            for (int y = i; y < m; ++y) f[j][y] = (3 - f[j][y]) % 3;
            g[j] = (3 - g[j]) % 3;
        }
        for (int x = 0; x < r; ++x) {
            if (f[x][i] != 0 && x != j) {
                int v = f[x][i];
                for (int y = i; y < m; ++y) f[x][y] = (f[x][y] - v * f[j][y] % 3 + 3) % 3;
                g[x] = (g[x] - v * g[j] % 3 + 3) % 3;
            }
        }
    }
    for (int i = Rank; i < r; ++i) {
        if (g[i] != 0) {
            std::cout << "-1\n";
            return;
        }
    }
    for (int i = Rank - 1; i >= 0; i--) {
        int j = 0;
        while (f[i][j] == 0) ++j;
        Col[j] = g[i];
    }
    for (int i = 0; i < m; ++i) std::cout << Col[i] + 1 << " \n"[i == m - 1];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) Solve();
    return 0;
}