#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) std::cin >> c[i];
    int tot = std::accumulate(c.begin(), c.end(), 0);
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<int> siz(n), f(n), usiz(n), uf(n), good(n);
    std::function<void(int, int)> dfs1 = [&](int u, int p) {
        siz[u] = c[u];
        int x = c[u];
        for (auto v : adj[u]) {
            if (v == p) continue;
            dfs1(v, u);
            x |= c[v];
            siz[u] += siz[v];
            f[u] |= f[v];
        }
        f[u] |= x && siz[u] >= 2;
    };
    dfs1(0, -1);
    std::function<void(int, int)> Dfs2 = [&](int u, int p) {
        int x = c[u];
        int y = uf[u];
        for (auto v : adj[u]) {
            x += c[v];
            if (v != p) y += f[v];
        }
        good[u] = x > 0 || f[u] || uf[u];
        for (auto v : adj[u]) {
            if (v == p) continue;
            usiz[v] = tot - siz[v];
            uf[v] = y - f[v] > 0 || (x - c[v] > 0 && usiz[v] >= 2);
            Dfs2(v, u);
        }
    };
    Dfs2(0, -1);
    for (int i = 0; i < n; ++i) std::cout << good[i] << " \n"[i == n - 1];
    return 0;
}