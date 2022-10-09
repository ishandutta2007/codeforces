// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class T = int, class F = plus<T>>
struct segtree {
    int maxn;
    vector<T> a;
    T e;
    F f;

    segtree(int n, T e = T(), F f = F(), T v = T()) : e(e), f(f) {
        maxn = 1;
        while (maxn < n)
            maxn <<= 1;
        a.assign(2*maxn, v);
        for (int i=maxn-1; i; i--)
            a[i] = f(a[2*i], a[2*i+1]);
    }

    void add(int p, const T& v) {
        p += maxn;
        a[p] = f(a[p], v);
        for (p >>= 1; p; p >>= 1)
            a[p] = f(a[2*p], a[2*p+1]);
    }

    void set(int p, const T& v) {
        p += maxn;
        a[p] = v;
        for (p >>= 1; p; p >>= 1)
            a[p] = f(a[2*p], a[2*p+1]);
    }

    T get(int l, int r, int x, int xl, int xr) const {
        if (r <= xl || xr <= l)
            return e;
        if (l <= xl && xr <= r)
            return a[x];
        int xm = (xl+xr) >> 1;
        return f(get(l, r, 2*x, xl, xm), get(l, r, 2*x+1, xm, xr));
    }

    T operator() (int l, int r) const {
        return get(l, r, 1, 0, maxn);
    }
};

struct seg {
    ll s, f;

    seg operator+ (const seg& b) const {
        return {s + b.s, min(f, s + b.f)};
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        segtree<seg> st(n);
        for (int i=0; i<n; i++) {
            ll x;
            cin >> x;
            st.set(i, {x, min(0ll, x)});
        }

        int blen = -1, bl = -1, br = -1;

        for (int l : ra(0, n)) {
            int r = *R::partition_point(ra(l+1, n+1), [&](int m) {
                return st(l, m).f + s >= 0;
            }) - 1;

            if (r > l && r - l > blen) {
                blen = r - l;
                bl = l, br = r;
            }
        }

        if (bl == -1) {
            cout << "-1\n";
        } else {
            cout << bl+1 << ' ' << br << '\n';
        }
    }
}