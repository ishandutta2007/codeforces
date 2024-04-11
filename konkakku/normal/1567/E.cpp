#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

long long calc(int u) {
    return 1LL * u * (u + 1) / 2;
}

struct node {
    int sz, ls, rs, lv, rv;
    long long ans;

    node(int _u = 0) {
        ls = rs = sz = 1;
        lv = rv = _u;
        ans = 1;
    }

    node operator+(const node &oth) {
        node ret;
        ret.lv = lv; ret.rv = oth.rv; ret.sz = sz + oth.sz;
        if (rv > oth.lv) {
            ret.ans = ans + oth.ans;
            ret.ls = ls;
            ret.rs = oth.rs;
        } else {
            ret.ans = ans + oth.ans - calc(rs) - calc(oth.ls) + calc(rs + oth.ls);
            ret.ls = (ls == sz ? ls + oth.ls : ls);
            ret.rs = (oth.rs == oth.sz ? oth.rs + rs : oth.rs);
        }
        return ret;
    }
};

struct segment_tree {
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1

    node tr[4 * N];

    void update_point(int l, int r, int i, int u, int v) {
        if (l == r) {
            tr[i] = node(v);
        } else {
            if (u <= m) {
                update_point(l, m, lc, u, v);
            } else {
                update_point(m + 1, r, rc, u, v);
            }
            tr[i] = tr[lc] + tr[rc];
        }
    }

    node query(int l, int r, int i, int L, int R) {
        if (L <= l && r <= R) {
            return tr[i];
        } else {
            if (R <= m) {
                return query(l, m, lc, L, R);
            } else if (L > m) {
                return query(m + 1, r, rc, L, R);
            } else {
                return query(l, m, lc, L, R) + query(m + 1, r, rc, L, R);
            }
        }
    }
} seg;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int u; cin >> u;
        seg.update_point(1, n, 1, i, u);
    }
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, y; cin >> x >> y;
            seg.update_point(1, n, 1, x, y);
        } else {
            int l, r; cin >> l >> r;
            cout << seg.query(1, n, 1, l, r).ans << '\n';
        }
    }
}