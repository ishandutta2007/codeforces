#include <iostream>
#include <vector>
#include <algorithm>
int n, q;
std::vector<int> sz, top, dep, parent;
std::vector<std::vector<int>> e;
void dfsSz(int u) {
    if (parent[u] != -1)
        e[u].erase(std::find(e[u].begin(), e[u].end(), parent[u]));
    sz[u] = 1;
    for (int &v : e[u]) {
        parent[v] = u;
        dep[v] = dep[u] + 1;
        dfsSz(v);
        sz[u] += sz[v];
        if (sz[v] > sz[e[u][0]])
            std::swap(v, e[u][0]);
    }
}
void dfsHLD(int u) {
    for (int v : e[u]) {
        if (v == e[u][0]) {
            top[v] = top[u];
        } else {
            top[v] = v;
        }
        dfsHLD(v);
    }
}
int lca(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]]) {
            u = parent[top[u]];
        } else {
            v = parent[top[v]];
        }
    }
    if (dep[u] < dep[v]) {
        return u;
    } else {
        return v;
    }
}
int dist(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    e.resize(n);
    sz.resize(n);
    dep.resize(n);
    top.resize(n);
    parent.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    parent[0] = -1;
    dfsSz(0);
    dfsHLD(0);
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        int x, y, a, b, k;
        std::cin >> x >> y >> a >> b >> k;
        --x;
        --y;
        --a;
        --b;
        int p = dist(a, b);
        int l = std::min(dist(a, x) + dist(b, y), dist(a, y) + dist(b, x)) + 1;
        if ((k >= p && (k - p) % 2 == 0) || (k >= l && (k - l) % 2 == 0)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}