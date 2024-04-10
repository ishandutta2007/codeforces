// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class W, class T = int, class F = plus<T>>
struct implicit_segtree {
    struct node { T v; int l; int r; };
    node dn() { return {e, ~0, ~0}; }
    int nn() { a.emplace_back(dn()); return a.size() - 1; }

    T e;
    F f;
    W rl, rr;
    vector<node> a;

    implicit_segtree(W rl = 0, W rr = 200005, T e = T(), F f = F()) :
        e(e), f(f), rl(rl), rr(rr), a(1, dn()) {}

    template<class L>
    int _au(W p, const T& v, int x, W xl, W xr, L op) {
        if (!~x) x = nn();
        if (xr - xl == 1) {
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

    T get(W l, W r, int x, W xl, W xr) const {
        if (!~x || r <= xl || xr <= l)
            return e;
        if (l <= xl && xr <= r)
            return a[x].v;
        W xm = midpoint(xl, xr);
        return f(get(l, r, a[x].l, xl, xm), get(l, r, a[x].r, xm, xr));
    }

    T operator() (W l, W r) const { return get(l, r, 0, rl, rr); }
};

template<class T = int>
struct maxval {
    T x;
    maxval(T x = numeric_limits<T>::min()) : x(x) {}
    T operator() () const { return x; }
    maxval operator+ (const maxval& b) const { return max(x, b.x); }
    maxval& operator+= (const maxval& b) { x = max(x, b.x); return *this; }
};

using mvi = maxval<int>;
using simp = implicit_segtree<int, mvi>;

struct segtree {
    constexpr static int maxn = 1 << 18;
    vector<simp> a;

    segtree() : a(2*maxn) {}

    void add(int p, int y, int v) {
        for (p += maxn; p; p >>= 1)
            a[p].add(y, v);
    }

    mvi get(int l, int r, int yl, int yr, int x, int xl, int xr) const {
        if (r <= xl || xr <= l)
            return {};
        if (l <= xl && xr <= r)
            return a[x](yl, yr);
        int xm = (xl+xr) >> 1;
        return get(l, r, yl, yr, 2*x, xl, xm) + get(l, r, yl, yr, 2*x+1, xm, xr);
    }

    mvi operator() (int xl, int xr, int yl, int yr) const {
        return get(xl, xr, yl, yr, 1, 0, maxn);
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, sol = 0;
    cin >> n;

    segtree st;
    st.add(0, 0, 0);

    for (int i : ra(1, n+1)) {
        int x;
        cin >> x;
        if (i-x < 0) continue;
        int w = st(0, x, 0, i-x+1)() + 1;
        st.add(x, i-x, w);
        sol = max(sol, w);
    }

    cout << sol << '\n';
}