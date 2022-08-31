#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
int n, k, r, q, dfsClock;
std::vector<int> belong, dis, fa, sz, top, dep, parent, dfn, dfa;
std::vector<std::vector<int>> e;
std::queue<int> que;
int find(int x) {
    while (fa[x] >= 0 && fa[fa[x]] >= 0)
        x = fa[x] = fa[fa[x]];
    return fa[x] >= 0 ? fa[x] : x;
}
bool query(int x, int y) {
    return find(x) == find(y);
}
bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return false;
    if (fa[x] > fa[y])
        std::swap(x, y);
    fa[x] += fa[y];
    fa[y] = x;
    return true;
}
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
    dfn[u] = dfsClock++;
    dfa[dfn[u]] = u;
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
int ancester(int u, int d) {
    while (dep[top[u]] > d)
        u = parent[top[u]];
    return dfa[dfn[u] - dep[u] + d];
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> k >> r;
    belong.assign(2 * n - 1, -1);
    dis.resize(2 * n - 1);
    fa.assign(2 * n - 1, -1);
    sz.resize(2 * n - 1);
    top.resize(2 * n - 1);
    dep.resize(2 * n - 1);
    parent.resize(2 * n - 1);
    dfn.resize(2 * n - 1);
    dfa.resize(2 * n - 1);
    e.resize(2 * n - 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].push_back(n + i);
        e[n + i].push_back(u);
        e[v].push_back(n + i);
        e[n + i].push_back(v);
    }
    for (int i = 0; i < r; ++i) {
        int x;
        std::cin >> x;
        --x;
        belong[x] = x;
        que.push(x);
    }
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        if (dis[u] == k)
            continue;
        for (int v : e[u]) {
            if (belong[v] == -1) {
                belong[v] = belong[u];
                dis[v] = dis[u] + 1;
                que.push(v);
            } else {
                merge(belong[u], belong[v]);
            }
        }
    }
    parent[0] = -1;
    dfsSz(0);
    dfsHLD(0);
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        int l = lca(u, v);
        if (dep[u] + dep[v] - 2 * dep[l] <= 2 * k) {
            std::cout << "YES\n";
        } else {
            int x = dep[u] - dep[l] >= k ? ancester(u, dep[u] - k) : ancester(v, 2 * dep[l] - dep[u] + k);
            int y = dep[v] - dep[l] >= k ? ancester(v, dep[v] - k) : ancester(u, 2 * dep[l] - dep[v] + k);
            if (belong[x] != -1 && belong[y] != -1 && query(belong[x], belong[y])) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
        }
    }
    return 0;
}