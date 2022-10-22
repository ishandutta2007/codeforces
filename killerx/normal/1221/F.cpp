#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct SegmentTree {
    static const int Sz = 1 << 19, Lg = 19;
    ll mx[Sz << 1];
    int mxid[Sz << 1];
    ll tag[Sz << 1];
    SegmentTree() {
        memset(mx, -0x3f, sizeof(mx));
        memset(mxid, -1, sizeof(mxid));
        memset(tag, 0, sizeof(tag));
    }
    void push(int x, ll v) { mx[x] += v; tag[x] += v; }
    void pushdown(int x) { if (tag[x]) push(x << 1, tag[x]), push(x << 1 | 1, tag[x]), tag[x] = 0; }
    void pushup(int x) {
        if (mx[x << 1] > mx[x << 1 | 1])
            mx[x] = mx[x << 1], mxid[x] = mxid[x << 1];
        else
            mx[x] = mx[x << 1 | 1], mxid[x] = mxid[x << 1 | 1];
    }
    void touch(int x, ll v) {
        x += Sz;
        mx[x] = v, mxid[x] = x - Sz;
        while (x >>= 1) pushup(x);
    }
    void upd(int l, int r, ll v) {
        l += Sz, r += Sz;
        for (int i = Lg; i; -- i) {
            if (((l >> i) << i) != l) pushdown(l >> i);
            if (((r >> i) << i) != r) pushdown(r >> i);
        }
        int l0 = l, r0 = r;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) push(l ++, v);
            if (r & 1) push(-- r, v);
        }
        for (int i = 1; i <= Lg; ++ i) {
            if (((l0 >> i) << i) != l0) pushup(l0 >> i);
            if (((r0 >> i) << i) != r0) pushup(r0 >> i);
        }
    }
    pair <ll, int> op(pair <ll, int> a, int x) {
        if (a.first > mx[x]) return a;
        else return mp(mx[x], mxid[x]);
    }
    pair <ll, int> qry(int l, int r) {
        l += Sz, r += Sz;
        for (int i = Lg; i; -- i) {
            if (((l >> i) << i) != l) pushdown(l >> i);
            if (((r >> i) << i) != r) pushdown(r >> i);
        }
        pair <ll, int> ans(-(1LL << 60), -1);
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = op(ans, l ++);
            if (r & 1) ans = op(ans, -- r);
        }
        return ans;
    }
} seg;

struct Point {
    int x, y, c;
    bool operator < (const Point &o) const { return max(x, y) < max(o.x, o.y); }
} p[500005];

int n;
vector <int> vec;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    rep(i, n) cin >> p[i].x >> p[i].y >> p[i].c;
    ll ans = -(1LL << 60);
    int aa = -1, ab = -1;
    rep(i, n) vec.pb(min(p[i].x, p[i].y));
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    rep(i, vec.size()) seg.touch(i, +vec[i]);
    sort(p, p + n);
    int j = 0;
    ll sum = 0;
    rep(i, n) {
        int a = max(p[i].x, p[i].y);
        sum += p[i].c;
        int ps = lower_bound(vec.begin(), vec.end(), min(p[i].x, p[i].y)) - vec.begin();
        seg.upd(ps + 1, vec.size(), -p[i].c);
        while (j < vec.size() && vec[j] <= a) ++ j;
        if (i + 1 == n || max(p[i].x, p[i].y) != max(p[i + 1].x, p[i + 1].y)) {
            pair <ll, int> pr = seg.qry(0, j);
            int b = vec[pr.second];
            ll cur = -a + sum + pr.first;
            if (cur > ans) {
                ans = cur;
                aa = a;
                ab = b;
            }
        }
    }
    if (ans < 0) {
        ans = 0;
        aa = ab = 2e9;
    }
    cout << ans << endl;
    cout << ab << " " << ab << " " << aa << " " << aa << endl;
    return 0;
}