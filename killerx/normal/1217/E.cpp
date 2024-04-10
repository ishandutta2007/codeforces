#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct SegmentTree {
    static const int Sz = 1 << 18;
    int mn[Sz << 1], mn0[Sz << 1];
    void pushup(int x) {
        if (mn[x << 1] < mn[x << 1 | 1]) mn[x] = mn[x << 1], mn0[x] = min(mn0[x << 1], mn[x << 1 | 1]);
        else mn[x] = mn[x << 1 | 1], mn0[x] = min(mn[x << 1], mn0[x << 1 | 1]);
    }
    void upd(int x, int v) {
        x += Sz;
        mn[x] = v, mn0[x] = 0x3f3f3f3f;
        while (x >>= 1) pushup(x);
    }
    pair <int, int> op(pair <int, int> a, int x) {
        if (a.first < mn[x]) return mp(a.first, min(a.second, mn[x]));
        else return mp(mn[x], min(a.first, mn0[x]));
    }
    pair <int, int> qry(int l, int r) {
        pair <int, int> ans(0x3f3f3f3f, 0x3f3f3f3f);
        for (l += Sz, r += Sz; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = op(ans, l ++);
            if (r & 1) ans = op(ans, -- r);
        }
        return ans;
    }
} seg[10];

void ins(int p, int x) {
    int e = 1;
    rep(i, 10) {
        int xi = (x / e) % 10;
        if (xi != 0) seg[i].upd(p, x);
        else seg[i].upd(p, 0x3f3f3f3f);
        e = e * 10;
    }
}

int n, q;
int a[200005];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> q;
    rep(i, n) cin >> a[i];
    rep(i, n) ins(i, a[i]);
    while (q --) {
        int op;
        cin >> op;
        switch(op) {
            case 1:
                int p, x;
                cin >> p >> x;
                -- p;
                ins(p, a[p] = x);
                break;
            case 2:
                int l, r;
                cin >> l >> r;
                -- l;
                int ans = 0x3f3f3f3f * 2;
                rep(i, 10) {
                    pair <int, int> cur = seg[i].qry(l, r);
                    if (cur.second > 1e9) continue;
                    ans = min(ans, cur.first + cur.second);
                }
                if (ans > 2e9) cout << -1 << '\n';
                else cout << ans << '\n';
                break;
        }
    }
    return 0;
}