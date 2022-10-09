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
    int e(int x) {
        if (p[x] == x) return x;
        return p[x] = e(p[x]);
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

    tree_topology(const vector<pair<int, int>>& b) {
        n = b.size() + 1;
        p.resize(n);
        e.resize(n);
        d = l = r = p;
        for (auto l : b) {
            int x, y;
            tie(x, y) = l;
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

    tree_topology_ex(const vector<pair<int, int>>& b, int logd) : tree_topology(b), logd(logd) {
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

struct edge {
    int w, u, v;
    strong_ordering operator<=> (const edge& b) const = default;
};

template<class F>
struct custom_segtree {
    F f;
    vector<int> a, b, lz;
    int maxn;

    custom_segtree(int n, F f) : f(f) {
        maxn = 1;
        while (maxn <= n) maxn <<= 1;
        a.resize(2*maxn, -1);
        for (int i : ra(1, n+1)) a[i + maxn] = i;
        for (int i=maxn-1; i; i--) a[i] = f(a[2*i], a[2*i+1]);
        b.resize(2*maxn, -1);
        lz.resize(2*maxn, -1);
    }

    void push(int x) {
        if (lz[x] == -1) return;
        b[x] = lz[x] ? a[x] : -1;
        if (x < maxn) {
            lz[2*x] = lz[x];
            lz[2*x+1] = lz[x];
        }
        lz[x] = -1;
    }

    void update(int l, int r, int v, int x, int xl, int xr) {
        if (r <= xl || xr <= l) return push(x);
        if (l <= xl && xr <= r) {
            lz[x] = v;
            return push(x);
        }

        push(x);
        int xm = (xl+xr) >> 1;
        update(l, r, v, 2*x, xl, xm);
        update(l, r, v, 2*x+1, xm, xr);
        b[x] = f(b[2*x], b[2*x+1]);
    }

    void update(int l, int r, int v) {
        update(l, r, v, 1, 0, maxn);
    }

    int operator() () {
        push(1);
        return b[1];
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, q;
    cin >> n >> q;
    vector<edge> edges;
    for (int i : ra(0, n-1)) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    R::sort(edges);

    vector<int> wt(2*n, -1);
    vector<pair<int, int>> aux_edges;
    {
        union_find uf(2*n);
        int k = n;
        for (auto [w, u, v] : edges) {
            k++;
            u = uf.e(u);
            v = uf.e(v);
            uf.p[u] = k;
            uf.p[v] = k;
            aux_edges.emplace_back(u, k);
            aux_edges.emplace_back(v, k);
            wt[k] = w;
        }
        aux_edges.emplace_back(k, 0);
    }

    tree_topology_ex tte(aux_edges, 20);

    auto lca_ex = [&](int x, int y) {
        if (x == -1) return y;
        if (y == -1) return x;
        return tte.lca(x, y);
    };

    custom_segtree st(n+1, lca_ex);

    while (q--) {
        int t;
        cin >> t;
        if (t <= 2) {
            int l, r;
            cin >> l >> r;
            st.update(l, r+1, 2-t);
        } else {
            int x;
            cin >> x;
            cout << wt[lca_ex(st(), x)] << '\n';
        }
    }
}