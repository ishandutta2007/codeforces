#include <iostream>
#include <vector>
#include <tuple>
int n, m;
std::vector<std::pair<int, int>> edges;
std::vector<std::vector<int>> e;
std::vector<int> dep, parent, f;
std::vector<std::tuple<int, int, int>> passengers;
void dfs(int u) {
    for (int v : e[u]) {
        if (v != parent[u]) {
            dep[v] = dep[u] + 1;
            parent[v] = u;
            dfs(v);
        }
    }
}
void cover(int u, int v, int w) {
    while (u != v) {
        if (dep[u] < dep[v]) {
            f[v] = std::max(f[v], w);
            v = parent[v];
        } else {
            f[u] = std::max(f[u], w);
            u = parent[u];
        }
    }
}
int queryMin(int u, int v) {
    int w = 1'000'000;
    while (u != v) {
        if (dep[u] < dep[v]) {
            w = std::min(f[v], w);
            v = parent[v];
        } else {
            w = std::min(f[u], w);
            u = parent[u];
        }
    }
    return w;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    edges.resize(n - 1);
    e.resize(n);
    dep.resize(n);
    parent.resize(n);
    f.assign(n, 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        edges[i] = {u, v};
        e[u].push_back(v);
        e[v].push_back(u);
    }
    parent[0] = -1;
    dfs(0);
    std::cin >> m;
    passengers.resize(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        --u;
        --v;
        cover(u, v, w);
        passengers[i] = {u, v, w};
    }
    for (auto [u, v, w] : passengers) {
        if (queryMin(u, v) != w) {
            std::cout << -1 << "\n";
            return 0;
        }
    }
    for (auto [u, v] : edges) {
        if (parent[u] == v)
            std::swap(u, v);
        std::cout << f[v] << " ";
    }
    std::cout << "\n";
    return 0;
}