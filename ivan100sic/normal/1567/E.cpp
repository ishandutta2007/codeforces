// Retired?
#include <bits/stdc++.h>
using namespace std;

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

struct node {
    ll p, q, w, s;

    node() {
        p = q = w = s = 0;
    }

    node(int x) {
        s = 0;
        w = 1;
        p = q = x;
    }

    node operator+ (const node& b) const {
        node t;
        t.w = w + b.w;
        t.s = s + b.s;
        if (p == w && b.p == b.w) {
            t.p = t.q = t.w;
        } else if (p != w && b.p != b.w) {
            t.p = p;
            t.q = b.q;
            t.s += (q + b.p)*(q + b.p + 1) / 2;
        } else if (p == w && b.p != b.w) {
            t.p = p + b.p;
            t.q = b.q;
        } else {
            t.p = p;
            t.q = q + b.q;
        }

        return t;
    }

    ll operator() () const {
        if (p == w) {
            return w*(w+1) / 2;
        } else {
            return s + p*(p+1) / 2 + q*(q+1) / 2;
        }
    }
};

int n, q;
int a[200005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> q;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    segtree<node> st(n-1);

    for (int i=0; i<n-1; i++) {
        st.set(i, a[i] <= a[i+1]);
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            x--;
            a[x] = y;
            if (x > 0) st.set(x-1, a[x-1] <= a[x]);
            st.set(x, a[x] <= a[x+1]);
        } else {
            int l, r;
            cin >> l >> r;
            cout << st(l-1, r-1)() + r-l+1 << '\n';
        }
    }
}