#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct RangeMinimumQuery {
    vector <int> v;
    vector <vector <int> > mn;
    vector <int> _lg;

    RangeMinimumQuery(const vector <int> &_v) {
        v = _v;
        int n = v.size();
        mn.resize(20);
        rep(i, mn.size()) mn[i].resize(n);
        rep(i, n) mn[0][i] = v[i];
        rep(j, 20 - 1) rep(i, n - (1 << (j + 1)) + 1)
            mn[j + 1][i] = min(mn[j][i], mn[j][i + (1 << j)]);
        _lg.resize(n + 1);
        rep(i, n + 1) if (i > 1) _lg[i] = _lg[i >> 1] + 1;
    }

    int qry(int l, int r) {
        if (l == r) return 1e9 + 7;
        int k = _lg[r - l];
        return min(mn[k][l], mn[k][r - (1 << k)]);
    }

    int per_qry(int l, int r) {
        if (l == r) return 1e9 + 7;
        if (r - l >= v.size()) return qry(0, v.size());
        int nl = l % v.size(), nr = r % v.size();
        if (nl < nr) return qry(nl, nr);
        else return min(qry(nl, v.size()), qry(0, nr));
    }
};

struct SegmentTreeLazy {
    int sz, _lg;
    vector <int> tag, mn;

    inline void push(int x, int v) { mn[x] = v, tag[x] = v; }
    inline void pushdown(int x) { if (tag[x] != -1) push(x << 1, tag[x]), push(x << 1 | 1, tag[x]), tag[x] = -1; }
    inline void pushup(int x) { mn[x] = min(mn[x << 1], mn[x << 1 | 1]); }

    SegmentTreeLazy(const vector <int> &v) {
        int n = v.size();
        for (sz = 1, _lg = 0; sz < n; sz <<= 1, ++ _lg);
        tag.resize(sz << 1, -1);
        mn.resize(sz << 1, 1e9 + 7);
        rep(i, n) mn[i + sz] = v[i];
        for (int i = sz - 1; i; -- i) pushup(i);
    }

    void upd(int l, int r, int v) {
        l += sz, r += sz;
        for (int i = _lg; i; -- i) {
            if (((l >> i) << i) != l) pushdown(l >> i);
            if (((r >> i) << i) != r) pushdown(r >> i);
        }
        int l0 = l, r0 = r;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) push(l ++, v);
            if (r & 1) push(-- r, v);
        }
        for (int i = 1; i <= _lg; ++ i) {
            if (((l0 >> i) << i) != l0) pushup(l0 >> i);
            if (((r0 >> i) << i) != r0) pushup(r0 >> i);
        }
    }

    int qry(int l, int r) {
        l += sz, r += sz;
        for (int i = _lg; i; -- i) {
            if (((l >> i) << i) != l) pushdown(l >> i);
            if (((r >> i) << i) != r) pushdown(r >> i);
        }
        int ans = 1e9 + 7;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = min(ans, mn[l ++]);
            if (r & 1) ans = min(ans, mn[-- r]);
        }
        return ans;
    }
};

int n, k, b[100005], mb, q;

struct Qry {
    int tp, l, r, x;
} qry[100005];

vector <int> sepr, ini;

int main() {
    scanf("%d %d", &n, &k);
    rep(i, n) scanf("%d", &b[i]);
    mb = b[0];
    rep(i, n) mb = min(mb, b[i]);
    RangeMinimumQuery rmq(vector <int> (b, b + n));
    scanf("%d", &q);
    rep(i, q) {
        scanf("%d %d %d", &qry[i].tp, &qry[i].l, &qry[i].r);
        -- qry[i].l;
        sepr.pb(qry[i].l), sepr.pb(qry[i].r);
        if (qry[i].tp == 1) scanf("%d", &qry[i].x);
    }
    sepr.pb(0);
    sepr.pb(k * n);
    sort(sepr.begin(), sepr.end());
    sepr.erase(unique(sepr.begin(), sepr.end()), sepr.end());
    rep(i, sepr.size() - 1) ini.pb(rmq.per_qry(sepr[i], sepr[i + 1]));
    SegmentTreeLazy seg(ini);
    rep(i, q) {
        int l = lower_bound(sepr.begin(), sepr.end(), qry[i].l) - sepr.begin();
        int r = lower_bound(sepr.begin(), sepr.end(), qry[i].r) - sepr.begin();
        if (qry[i].tp == 1) seg.upd(l, r, qry[i].x);
        else printf("%d\n", seg.qry(l, r));
    }
    return 0;
}