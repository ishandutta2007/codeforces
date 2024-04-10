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

    implicit_segtree(W rl, W rr, T e = T(), F f = F()) :
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

template<class T = int>
struct maxval {
    T x;
    maxval(T x = numeric_limits<T>::min()) : x(x) {}
    T operator() () const { return x; }
    maxval operator+ (const maxval& b) const { return max(x, b.x); }
    maxval& operator+= (const maxval& b) { x = max(x, b.x); return *this; }
};

using mxi = maxval<int>;

struct man {
    int s, a;
};

int n, d;
vector<man> good, bad;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> d;
    for (int i=0; i<n; i++) {
        int s, a;
        cin >> s >> a;
        if (s < d) continue;

        if (s >= a) {
            good.push_back({s, a});
        } else {
            bad.push_back({s, a});
        }
    }

    R::sort(good, {}, &man::s);
    R::sort(bad, {}, &man::a);

    implicit_segtree<int, mxi> ist(-1, int(1e9 + 5));
    ist.add(-1, 0);

    int i = 0, gr = -1;
    for (int j : ra(0, ssize(bad))) {
        // cerr << "at " << j << '\n';
        while (i < ssize(good) && good[i].s < bad[j].a) {
            gr = max(gr, good[i].a);
            i++;
        }

        // cerr << "gr = " << gr << '\n';
        if (gr <= bad[j].s) {
            // cerr << "picking " << j << '\n';
            ist.add(bad[j].a, ist(-1, bad[j].s + 1)() + 1);
        }
    }

    cout << good.size() + ist(-1, 1e9 + 5)() << '\n';
}