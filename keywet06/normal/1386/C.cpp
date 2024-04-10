#include <bits/stdc++.h>

struct DSU {
    std::vector<int> fa, d;
    std::vector<std::pair<int *, int>> his;
    DSU(int n) : fa(n, -1), d(n, 0) {}
    std::pair<int, int> find(int x) {
        int dis = 0;
        while (fa[x] >= 0)
            dis ^= d[x], x = fa[x];
        return {x, dis};
    }
    void modify(int &x, int y) {
        his.emplace_back(&x, x);
        x = y;
    }
    void undo(int x) {
        while (int(his.size()) > x) {
            *his.back().first = his.back().second;
            his.pop_back();
        }
    }
    bool merge(int x, int y) {
        auto [a, f] = find(x);
        auto [b, g] = find(y);
        if (a == b) {
            return f != g;
        } else if (fa[a] < fa[b]) {
            modify(fa[a], fa[a] + fa[b]);
            modify(fa[b], a);
            modify(d[b], f ^ g ^ 1);
            return true;
        } else {
            modify(fa[b], fa[b] + fa[a]);
            modify(fa[a], b);
            modify(d[a], f ^ g ^ 1);
            return true;
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<int> mn(m);
    std::vector<int> u(m), v(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> u[i] >> v[i];
        --u[i];
        --v[i];
    }
    DSU dsu(n);
    int x = 0;
    while (x < m && dsu.merge(u[x], v[x]))
        ++x;
    for (int i = x + 1; i < m; ++i)
        mn[i] = m + 1;
    dsu.undo(0);
    std::function<void(int, int, int)> solve = [&](int l, int r, int y) {
        if (l == r)
            return;
        int m = (l + r) / 2;
        int x = dsu.his.size();
        for (int i = l; i < m; ++i)
            dsu.merge(u[i], v[i]);
        int x1 = dsu.his.size();
        int y0 = y;
        while (y0 > m && dsu.merge(u[y0 - 1], v[y0 - 1]))
            --y0;
        mn[m] = y0;
        dsu.undo(x1);
        dsu.merge(u[m], v[m]);
        solve(m + 1, r, y);
        dsu.undo(x);
        for (int i = y0; i < y; ++i)
            dsu.merge(u[i], v[i]);
        solve(l, m, y0);
        dsu.undo(x);
    };
    solve(0, std::min(m, x + 1), m);
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        --l;
        if (r >= mn[l]) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    }
    return 0;
}