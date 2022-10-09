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
    maxval(T x = numeric_limits<T>::min()/2) : x(x) {}
    T operator() () const { return x; }
    maxval operator+ (const maxval& b) const { return max(x, b.x); }
    maxval& operator+= (const maxval& b) { x = max(x, b.x); return *this; }
};

using mxll = maxval<ll>;
const ll inf = 2012012012;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<array<int, 4>> a(3*n);
        for (int i : ra(0, n)) {
            int x, p;
            cin >> x >> p;
            a[3*i+0] = {x-p, p, i, 0};
            a[3*i+1] = {x, p, i, 1};
            a[3*i+2] = {x+p, p, i, 2};
        }

        R::sort(a);
        multiset<int> up, dn;
        ll ups = 0, dns = 0;

        implicit_segtree plus(-inf, inf, mxll{});
        implicit_segtree minus(-inf, inf, mxll{});
        implicit_segtree zero(-inf, inf, mxll{});
        
        for (auto [x, p, i, t] : a) {
            if (t == 0) {
                up.insert(x);
                ups += x;
            } else if (t == 2) {
                dn.erase(dn.find(x));
                dns -= x;
            } else {
                up.erase(up.find(x-p));
                ups -= x-p;
                dn.insert(x+p);
                dns += x+p;

                ll sum = ssize(up)*x - ups;
                sum += dns - ssize(dn)*x;
                plus.add(x, sum+x);
                zero.add(x, sum);
                minus.add(x, sum-x);
            }
        }

        string sol(n, 0);
        for (auto [x, p, i, t] : a) {
            if (t == 1) {
                auto left = zero(-inf, x-p)();
                auto rise = minus(x-p, x)() + (x-p);
                auto fall = plus(x, x+p)() - (x+p);
                auto right = zero(x+p, inf)();

                if (max({left, rise, fall, right}) <= m) {
                    sol[i] = '1';
                } else {
                    sol[i] = '0';
                }
            }
        }

        cout << sol << '\n';
    }
    
}