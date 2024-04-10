#include <bits/stdc++.h>

const int N = 1e3;

int parent[N], dep[N];

std::vector<int> e[N], depv[N];

std::pair<int, int> query(const std::vector<int> &v) {
    std::cout << "? " << v.size();
    for (auto i : v) std::cout << " " << i + 1;
    std::cout << std::endl;
    int a, d;
    std::cin >> a >> d;
    --a;
    return std::make_pair(a, d);
}

void dfs(int u) {
    depv[dep[u]].push_back(u);
    for (auto v : e[u]) {
        if (v == parent[u]) continue;
        parent[v] = u;
        dep[v] = dep[u] + 1;
        dfs(v);
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
            e[i].clear();
            depv[i].clear();
        }
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            std::cin >> u >> v;
            --u, --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        std::vector<int> p(n);
        std::iota(p.begin(), p.end(), 0);
        auto [root, dis] = query(p);
        parent[root] = -1;
        dep[root] = 0;
        dfs(root);
        int l = (dis + 1) / 2, r = dis;
        int u = -1;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (depv[m].empty()) {
                r = m - 1;
                continue;
            }
            auto [x, y] = query(depv[m]);
            if (y == dis) {
                u = x;
                l = m;
            } else {
                r = m - 1;
            }
        }
        if (u == -1) u = query(depv[l]).first;
        for (int i = u; i != root; i = parent[i]) {
            depv[dep[i]].erase(
                std::find(depv[dep[i]].begin(), depv[dep[i]].end(), i));
        }
        int v = query(depv[dis - dep[u]]).first;
        std::cout << "! " << u + 1 << " " << v + 1 << std::endl;
        std::string res;
        std::cin >> res;
    }
    return 0;
}