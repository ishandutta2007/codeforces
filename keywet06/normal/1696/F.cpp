#include <bits/stdc++.h>

void Solve() {
    int n;
    std::cin >> n;
    std::vector f(n, std::vector<std::string>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) std::cin >> f[i][j], f[j][i] = f[i][j];
    }
    for (int x = 1; x < n; ++x) {
        std::vector<bool> vis(n);
        vis[0] = vis[x] = true;
        std::vector<std::array<int, 2>> edges;
        edges.push_back({0, x});
        std::function<void(int, int)> check = [&](int u, int v) {
            for (int i = 0; i < n; ++i) {
                if (vis[i] || f[i][u][v] == '0') continue;
                vis[i] = true, edges.push_back({v, i}), check(v, i);
            }
        };
        check(0, x), check(x, 0);
        if (int(edges.size()) != n - 1) continue;
        bool ok = true;
        std::vector<std::vector<int>> adj(n);
        for (auto [u, v] : edges) adj[u].push_back(v), adj[v].push_back(u);
        std::vector Dis(n, std::vector<int>(n));
        for (int i = 0; i < n; ++i) {
            std::function<void(int, int)> Dfs = [&](int u, int p) {
                for (auto v : adj[u]) {
                    if (v == p) continue;
                    Dis[i][v] = Dis[i][u] + 1, Dfs(v, u);
                }
            };
            Dfs(i, -1);
        }

        for (int x = 0; x < n; ++x) {
            for (int y = x + 1; y < n; ++y) {
                for (int z = 0; z < n; ++z) {
                    if ((f[x][y][z] == '1') != (Dis[x][z] == Dis[y][z])) ok = false;
                }
            }
        }
        if (ok) {
            std::cout << "Yes\n";
            for (auto [u, v] : edges) std::cout << u + 1 << " " << v + 1 << "\n";
            return;
        }
    }
    std::cout << "No\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) Solve();
    return 0;
}