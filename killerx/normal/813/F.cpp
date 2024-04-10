#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct UnionFind {
    int n;
    int vio;
    vector <pair <int, int> > fa;
    vector <int> sz;
    vector <pair <int, int> > ops;

    UnionFind(int _n) {
        n = _n;
        vio = 0;
        fa.resize(n);
        sz.resize(n, 1);
        rep(i, n) fa[i] = mp(i, 0);
    }

    pair <int, int> find(int x) {
        if (x == fa[x].first) return fa[x];
        else {
            pair <int, int> pr = find(fa[x].first);
            return mp(pr.first, fa[x].second ^ pr.second);
        }
    }

    void merge(int x, int y) {
        int xw, yw;
        tie(x, xw) = find(x);
        tie(y, yw) = find(y);
        if (x == y) {
            if ((xw ^ yw ^ 1) == 1) ++ vio;
            return ;
        }
        if (sz[x] > sz[y]) swap(x, y);
        fa[x] = mp(y, xw ^ yw ^ 1);
        sz[y] += sz[x];
        ops.pb(mp(x, y));
    }

    pair <int, int> record() {
        return mp(ops.size(), vio);
    }

    void backtrack(pair <int, int> rec) {
        vio = rec.second;
        while (ops.size() > rec.first) {
            int x = ops.back().first;
            int y = ops.back().second;
            fa[x] = mp(x, 0);
            sz[y] -= sz[x];
            ops.pop_back();
        }
    }
};

struct SegmentTreeTime {
    int sz, n, q;
    UnionFind uf;
    vector <vector <pair <int, int> > > qry;

    SegmentTreeTime(int _n, int _q): uf(_n) {
        n = _n, q = _q;
        for (sz = 1; sz < q; sz <<= 1);
        qry.resize(sz << 1);
    }

    void upd(int l, int r, pair <int, int> pr) {
        for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            if (l & 1) qry[l ++].pb(pr);
            if (r & 1) qry[-- r].pb(pr);
        }
    }

    void solve(int i, int l, int r) {
        auto rec = uf.record();
        rep(j, qry[i].size()) {
            uf.merge(qry[i][j].first, qry[i][j].second);
        }
        if (l + 1 == r) {
            if (l < q) puts(uf.vio == 0 ? "YES" : "NO");
        } else {
            int m = (l + r) >> 1;
            solve(i << 1, l, m);
            solve(i << 1 | 1, m, r);
        }
        uf.backtrack(rec);
    }
};

int n, q;

int main() {
    scanf("%d %d", &n, &q);
    SegmentTreeTime seg(n, q);
    map <pair <int, int>, int> st;
    rep(i, q) {
        int u, v;
        scanf("%d %d", &u, &v);
        -- u, -- v;
        if (st.find(mp(u, v)) == st.end())
            st[mp(u, v)] = i;
        else {
            seg.upd(st[mp(u, v)], i, mp(u, v));
            st.erase(mp(u, v));
        }
    }
    for (auto it : st) seg.upd(it.second, q, it.first);
    seg.solve(1, 0, seg.sz);
    return 0;
}