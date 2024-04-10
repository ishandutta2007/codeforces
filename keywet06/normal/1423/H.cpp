#include <bits/stdc++.h>

struct dsu {
    std::vector<int> siz, f;
    std::vector<std::pair<int *, int>> his;
    dsu(int n) : siz(n, 1), f(n) { std::iota(f.begin(), f.end(), 0); }
    void merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (siz[u] < siz[v]) std::swap(u, v);
        his.emplace_back(&siz[u], siz[u]);
        siz[u] += siz[v];
        his.emplace_back(&f[v], f[v]);
        f[v] = u;
    }
    int find(int x) {
        while (x != f[x]) x = f[x];
        return x;
    }
    int size(int x) { return siz[find(x)]; }
    void undo(int x) {
        while (int(his.size()) > x) {
            *his.back().first = his.back().second;
            his.pop_back();
        }
    }
};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n, q, k;
    std::cin >> n >> q >> k;
    int tim = 0, day = 0;
    std::vector<std::tuple<int, int, int, int>> edges;
    std::vector<std::pair<int, int>> qry;
    std::vector<int> ed;
    std::vector<int> ans(q, -1);
    for (int i = 0; i < q; ++i) {
        int t;
        std::cin >> t;
        if (t == 1) {
            int u, v;
            std::cin >> u >> v;
            --u, --v;
            edges.emplace_back(u, v, tim, day);
        } else if (t == 2) {
            int x;
            std::cin >> x;
            --x;
            qry.emplace_back(x, tim);
            ++tim;
        } else {
            ed.push_back(tim);
            ++day;
        }
    }
    ed.push_back(tim);
    std::vector<std::vector<std::pair<int, int>>> f(4 * tim);
    auto add = [&](auto add, int p, int l, int r, int x, int y, auto edge) {
        if (l >= y || r <= x) return;
        if (l >= x && r <= y) {
            f[p].push_back(edge);
            return;
        }
        int m = (l + r) / 2;
        add(add, 2 * p, l, m, x, y, edge);
        add(add, 2 * p + 1, m, r, x, y, edge);
    };
    for (auto [u, v, x, d] : edges) {
        add(add, 1, 0, tim, x, ed[std::min(d + k - 1, day)],
            std::make_pair(u, v));
    }
    int cur = 0;
    dsu dsu(n);
    auto solve = [&](auto solve, int p, int l, int r) -> void {
        int mark = dsu.his.size();
        for (auto [u, v] : f[p]) dsu.merge(u, v);
        if (r - l == 1) {
            while (cur < int(qry.size()) && qry[cur].second == l) {
                std::cout << dsu.size(qry[cur++].first) << '\n';
            }
        } else {
            int m = (l + r) / 2;
            solve(solve, 2 * p, l, m);
            solve(solve, 2 * p + 1, m, r);
        }
        dsu.undo(mark);
    };
    solve(solve, 1, 0, tim);
    return 0;
}