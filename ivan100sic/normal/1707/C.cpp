// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct union_find {
    vector<int> p;
    union_find(int n) : p(n) { iota(begin(p), end(p), 0); }
    bool operator() (int x, int y) { return e(x) == e(y); }
    int e(int x) {
        if (p[x] == x) return x;
        return p[x] = e(p[x]);
    }
    bool join(int x, int y) {
        x = e(x), y = e(y);
        if (x == y) return false;
        p[x] = y;
        return true;
    }
};

struct tree_topology {
    int n;
    vector<int> p, d, l, r;
    vector<vector<int>> e;

    void dfs(int x, int& t) {
        l[x] = t++;
        for (int y : e[x]) {
            if (y == p[x]) continue;
            d[y] = d[x] + 1;
            p[y] = x;
            dfs(y, t);
        }
        r[x] = t;
    }

    tree_topology(const auto& b) {
        n = b.size() + 1;
        p.resize(n);
        e.resize(n);
        d = l = r = p;
        for (auto l : b) {
            int x, y;
            x = l[0];
            y = l[1];
            e[x].push_back(y);
            e[y].push_back(x);
        }
        p[0] = -1;
        int t = 0;
        dfs(0, t);
    }

    bool above(int x, int y) {
        return l[x] <= l[y] && r[y] <= r[x];
    }

    int size(int x) {
        return r[x] - l[x];
    }
};

struct tree_topology_ex : tree_topology {
    int logd;
    vector<vector<int>> a;

    tree_topology_ex(const auto& b, int logd) : tree_topology(b), logd(logd) {
        a.resize(logd);
        a[0] = p;
        for (int i=1; i<logd; i++) {
            a[i].resize(n);
            for (int j=0; j<n; j++) {
                a[i][j] = a[i-1][j] == -1 ? -1 : a[i-1][a[i-1][j]];
            }
        }
    }

    int lift(int x, int k) {
        for (int i=0; i<logd; i++) {
            if (x == -1) return -1;
            if (k & (1 << i)) x = a[i][x];
        }
        return x;
    }

    int lca(int x, int y) {
        if (d[x] > d[y]) swap(x, y);
        y = lift(y, d[y] - d[x]);
        if (x == y) return x;
        for (int i=logd-1; i>=0; i--) {
            int u = a[i][x], v = a[i][y];
            if (u != v) x = u, y = v;
        }
        return p[x];
    }

    int distance(int x, int y) {
        int z = lca(x, y);
        return d[x] + d[y] - 2*d[z];
    }

    int kth(int x, int y, int k) {
        int z = lca(x, y);
        if (k <= d[x] - d[y]) {
            return lift(x, k);
        } else {
            return lift(y, d[x] + d[y] - 2*d[z] - k);
        }
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, m;
    cin >> n >> m;

    union_find uf(n);

    vector<array<int, 2>> tree, bad;
    for (int i : ra(0, m)) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (!uf(x, y)) {
            tree.push_back({x, y});
            uf.join(x, y);
        } else {
            bad.push_back({x, y});
        }
    }

    tree_topology_ex tte(tree, 19);

    vector<ll> subtree(n), self(n);

    for (auto [x, y] : bad) {
        int z = tte.lca(x, y);
        if (z != x && z != y) {
            subtree[x]++;
            subtree[y]++;
        } else {
            if (z == y) swap(x, y);
            subtree[y]++;

            int xy = tte.lift(y, tte.d[y] - tte.d[x] - 1);
            subtree[0]++;
            subtree[xy]--;
        }
    }

    auto dfs = [&](int x, auto self) -> void {
        for (int y : tte.e[x]) {
            if (y == tte.p[x]) continue;

            subtree[y] += subtree[x];
            self(y, self);
        }
    };

    dfs(0, dfs);
    for (int i : ra(0, n)) {
        if (subtree[i] + self[i] == ssize(bad)) {
            cout << '1';
        } else {
            cout << '0';
        }
    }
    cout << '\n';
}