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

const ll large = 1e15;

struct cool_set {
    implicit_segtree<ll, mxi> ist;
    ll offset;
    map<ll, vector<int>> ref;

    cool_set() : ist(-large, large), offset(0) {}

    void add(ll key, int pos) {
        key -= offset;
        ist.add(key, pos);
        ref[key].push_back(pos);
    }

    int zeroes(int l) {
        auto it = ref.find(-offset);
        if (it == ref.end()) {
            return 0;
        }

        return it->second.end() - R::lower_bound(it->second, l);
    }

    void add_all(ll val) {
        offset += val;
    }

    mxi get_limit() {
        return ist(-large, -offset)();
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cool_set ev, od;
        ll sol = 0;
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            if (i % 2 == 0) {
                ev.add_all(x);
                od.add_all(-x);
                ev.add(x, i);
            } else {
                ev.add_all(-x);
                od.add_all(x);
                od.add(x, i);
            }

            int p = (ev.get_limit() + od.get_limit())();
            sol += ev.zeroes(p) + od.zeroes(p);
        }

        cout << sol << '\n';
    }
    
}