// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class W, class T = int, class F = plus<T>>
struct implicit_segtree {
    struct node { T v; int l; int r; };
    typedef typename make_unsigned<W>::type Wu;
    static inline W midpoint(W l, W r) { return l + (W)((Wu(r)-l) >> 1); }
    static inline bool is_leaf(W l, W r) { return Wu(r)-l == 1; }
    node dn() { return {e, ~0, ~0}; }
    int nn() { a.emplace_back(dn()); return a.size() - 1; }

    T e;
    F f;
    W rl, rr;
    vector<node> a;

    implicit_segtree(W rl, W rr, T e = T(), F f = F()) :
        e(e), f(f), rl(rl), rr(rr), a(1, dn()) {}

    template<class L>
    int _au(W p, const T& v, int x, W xl, W xr, L op) {
        if (!~x) x = nn();
        if (is_leaf(xl, xr)) {
            op(a[x].v, v);
        } else {
            W xm = midpoint(xl, xr);
            bool o = p < xm;
            int t = _au(p, v, o ? a[x].l : a[x].r, o ? xl : xm, o ? xm : xr, op);
            (o ? a[x].l : a[x].r) = t;
            a[x].v = f(~a[x].l ? a[a[x].l].v : e, ~a[x].r ? a[a[x].r].v : e);
        }
        return x;
    }

    void add(W p, const T& v) {
        _au(p, v, 0, rl, rr, [&](T& x, const T& y) { x = f(x, y); });
    }

    void set(W p, const T& v) {
        _au(p, v, 0, rl, rr, [&](T& x, const T& y) { x = y; });
    }

    T get(W l, W r, int x, W xl, W xr) {
        if (!~x || r <= xl || xr <= l)
            return e;
        if (l <= xl && xr <= r)
            return a[x].v;
        W xm = midpoint(xl, xr);
        return f(get(l, r, a[x].l, xl, xm), get(l, r, a[x].r, xm, xr));
    }

    T operator() (W l, W r) { return get(l, r, 0, rl, rr); }
};

struct minint2 {
    ll x, y;

    minint2(ll x = 1e18, ll y = 1e18) : x(x), y(y) {}

    minint2 operator+ (const minint2& b) const {
        return { min(x, b.x), min(y, b.y) };
    }
};

struct seg {
    ll a, b;

    bool operator< (const seg& o) const {
        return a < o.a;
    }
};

int n;
seg a[200005];
ll d[200005];
const ll inf = 1e18;


int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i=0; i<n; i++) {
        ll x, y;
        cin >> x >> y;
        a[i].a = x + y;
        a[i].b = x;
        d[i] = inf;
    }

    sort(a, a+n);
    d[0] = 0;

    const ll left = -1;
    const ll right = 3e9;
    implicit_segtree s(left, right, minint2());

    s.add(a[0].a, {d[0], d[0]-a[0].a});

    for (int i=1; i<n; i++) {
        ll va = s(left, a[i].b).y;
        ll vb = s(a[i].b, right).x;

        d[i] = min(vb, va + a[i].b);
        s.add(a[i].a, {d[i], d[i]-a[i].a});
    }

    ll sol = d[n-1];
    for (int i=0; i<n; i++) {
        sol += a[i].a - a[i].b;
    }

    cout << sol << '\n';
}