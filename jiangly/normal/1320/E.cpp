#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
int n, q, clk;
std::vector<int> sz, top, dep, parent, nodes, id, city, speed, imp, dfn, stk, tim, span;
std::vector<std::vector<int>> e;
std::set<std::tuple<int, int, int>> que;
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
    dfn[u] = clk++;
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
void solve(int u) {
    while (!e[u].empty() && id[e[u].back()] != -1)
        e[u].pop_back();
    if (e[u].empty())
        return;
    int v = e[u].back();
    int dis = std::abs(dep[u] - dep[v]) - span[u];
    int day = tim[u] + std::max(0, dis + speed[id[u]] - 1) / speed[id[u]];
    que.emplace(day, id[u], u);
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
    dfn.resize(n);
    id.resize(n);
    tim.resize(n);
    span.resize(n);
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
    for (int i = 0; i < n; ++i)
        e[i].clear();
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        int k, m;
        std::cin >> k >> m;
        nodes.clear();
        city.resize(k);
        speed.resize(k);
        for (int j = 0; j < k; ++j) {
            std::cin >> city[j] >> speed[j];
            --city[j];
            nodes.push_back(city[j]);
        }
        imp.resize(m);
        for (int j = 0; j < m; ++j) {
            std::cin >> imp[j];
            --imp[j];
            nodes.push_back(imp[j]);
        }
        nodes.push_back(0);
        std::sort(nodes.begin(), nodes.end(), [&](int u, int v) {
            return dfn[u] < dfn[v];
        });
        nodes.erase(std::unique(nodes.begin(), nodes.end()), nodes.end());
        stk = {0};
        int cnt = nodes.size();
        for (int i = 1; i < cnt; ++i) {
            int u = nodes[i];
            int l = lca(stk.back(), u);
            while (int(stk.size()) >= 2 && dep[l] <= dep[stk[stk.size() - 2]]) {
                e[stk[stk.size() - 2]].push_back(stk.back());
                e[stk.back()].push_back(stk[stk.size() - 2]);
                stk.pop_back();
            }
            if (l != stk.back()) {
                nodes.push_back(l);
                e[l].push_back(stk.back());
                e[stk.back()].push_back(l);
                stk.back() = l;
            }
            stk.push_back(u);
        }
        while (int(stk.size()) >= 2) {
            int u = stk.back();
            stk.pop_back();
            e[stk.back()].push_back(u);
            e[u].push_back(stk.back());
        }
        for (int u : nodes)
            id[u] = -1;
        for (int u : nodes)
            std::sort(e[u].begin(), e[u].end(), [&](int i, int j) {
                return std::abs(dep[i] - dep[u]) > std::abs(dep[j] - dep[u]);
            });
        for (int j = 0; j < k; ++j) {
            id[city[j]] = j;
            tim[city[j]] = 0;
            span[city[j]] = 0;
        }
        for (int j = 0; j < k; ++j)
            solve(city[j]);
        while (!que.empty()) {
            auto [day, vir, u] = *que.begin();
            que.erase(que.begin());
            while (!e[u].empty()) {
                int v = e[u].back();
                if (id[v] != -1) {
                    e[u].pop_back();
                    continue;
                }
                int dis = std::abs(dep[u] - dep[v]);
                if (span[u] + (day - tim[u]) * speed[id[u]] < dis)
                    break;
                e[u].pop_back();
                id[v] = id[u];
                tim[v] = day;
                span[v] = span[u] + (day - tim[u]) * speed[id[u]] - dis;
                solve(v);
            }
            solve(u);
        }
        for (int j = 0; j < m; ++j)
            std::cout << id[imp[j]] + 1 << " \n"[j == m - 1];
    }
    return 0;
}