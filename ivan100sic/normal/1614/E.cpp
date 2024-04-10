// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const int inf = 1'000'000'001;

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

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n;

    implicit_segtree<int, int> st(0, inf+2);

    auto st_lb = [&](int x) {
        return *R::lower_bound(ra(0, inf), true, {}, [&](int m) {
            return m + st(0, m+1) >= x;
        });
    };

    int lastans = 0;
    for (int x=1; x<=n; x++) {
        int temp;
        cin >> temp;

        int lb = st_lb(temp);
        int ub = st_lb(temp + 1);

        st.add(0, 1);
        st.add(lb, -1);
        st.add(ub, -1);

        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            x = (x + lastans) % inf;
            cout << (lastans = x + st(0, x+1)) << '\n';
        }
    }
}