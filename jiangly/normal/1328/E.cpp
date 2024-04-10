#include <iostream>
#include <vector>
#include <algorithm>
std::vector<std::vector<int>> e;
std::vector<int> parent, dep, dfn, sz;
int clock;
void dfs(int u) {
    dfn[u] = clock++;
    sz[u] = 1;
    for (int v : e[u]) {
        if (v == parent[u])
            continue;
        parent[v] = u;
        dep[v] = dep[u] + 1;
        dfs(v);
        sz[u] += sz[v];
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    e.resize(n);
    parent.resize(n);
    dep.resize(n);
    dfn.resize(n);
    sz.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(0);
    for (int i = 0; i < m; ++i) {
        int k;
        std::cin >> k;
        std::vector<int> v(k);
        for (int j = 0; j < k; ++j) {
            std::cin >> v[j];
            --v[j];
            v[j] = parent[v[j]];
        }
        std::sort(v.begin(), v.end(), [&](int u, int v) {
            return dep[u] < dep[v];
        });
        bool ok = true;
        for (int j = 0; j < k - 1; ++j)
            if (dfn[v[j + 1]] < dfn[v[j]] || dfn[v[j + 1]] >= dfn[v[j]] + sz[v[j]])
                ok = false;
        std::cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}