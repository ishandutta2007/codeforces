#include <bits/stdc++.h>

using i64 = long long;
using u64 = uint64_t;

void Solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> To(n);
    for (int i = 0, u, v; i < m; ++i) {
        std::cin >> u >> v, --u, --v;
        To[u].push_back(v);
        To[v].push_back(u);
    }
    std::vector<int> Col(n, -1), p(n), Dep(n);
    p[0] = -1, Col[0] = 0;
    std::function<void(int)> Dfs = [&](int u) {
        for (auto v : To[u]) {
            if (Col[v] == -1) p[v] = u, Dep[v] = Dep[u] + 1, Col[v] = Col[u] ^ 1, Dfs(v);
        }
    };
    Dfs(0);
    std::vector<int> f(n);
    int badEdges = 0;
    bool bad = false;
    for (int u = 0; u < n; ++u) {
        for (auto v : To[u]) {
            if (Col[u] == 0 && Col[v] == 0) bad = true;
            if (Dep[u] < Dep[v] && p[v] != u) {
                if (Col[u] == Col[v]) {
                    ++badEdges, ++f[v], --f[u];
                } else {
                    --f[v], ++f[u];
                }
            }
        }
    }
    if (badEdges <= 1) {
        if (bad) {
            for (int i = 0; i < n; ++i) Col[i] ^= 1;
        }
        std::cout << "YES\n";
        for (int i = 0; i < n; ++i) std::cout << Col[i];
        std::cout << "\n";
        return;
    }
    Dfs = [&](int u) {
        for (auto v : To[u]) {
            if (p[v] == u) Dfs(v), f[u] += f[v];
        }
    };
    Dfs(0);
    for (int i = 1; i < n; ++i) {
        if (f[i] == badEdges) {
            Dfs = [&](int u) {
                Col[u] ^= 1;
                for (auto v : To[u]) {
                    if (p[v] == u) Dfs(v);
                }
            };
            Dfs(i);
            if (Col[i] == 0) {
                for (int i = 0; i < n; ++i) Col[i] ^= 1;
            }
            std::cout << "YES\n";
            for (int i = 0; i < n; ++i) std::cout << Col[i];
            std::cout << "\n";
            return;
        }
    }
    std::cout << "NO\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) Solve();
    return 0;
}