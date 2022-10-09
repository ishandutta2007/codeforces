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

// [p ... q]
struct obj {
    bool neut;
    double p, q, last;

    obj() {
        p = q = last = 1;
        neut = true;
    }

    obj(double x) {
        neut = false;
        p = q = last = x;
    }

    obj operator+ (const obj& b) const {
        if (neut) return b;
        if (b.neut) return *this;

        obj rez;
        rez.neut = false;
        rez.last = b.last;
        //          [           y         ]
        rez.p = p * b.p / (1 - q + b.p * q);
        rez.q = 1 - (1-b.q)*(1-q) / (1 + q * (b.p - 1));
        return rez;
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, q;
    cin >> n >> q;

    segtree<obj> st(n);

    for (int i : ra(0, n)) {
        int p, q;
        cin >> p >> q;
        st.set(i, (double)p / q);
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, p, q;
            cin >> i >> p >> q;
            i--;
            st.set(i, (double)p / q);
        } else {
            int l, r;
            cin >> l >> r;
            l--;

            cout << st(l, r).p << '\n';
        }
    }
}