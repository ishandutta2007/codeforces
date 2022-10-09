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

template<class T = int>
struct minval {
    T x;
    minval(T x = numeric_limits<T>::max()) : x(x) {}
    T operator() () const { return x; }
    minval operator+ (const minval& b) const { return min(x, b.x); }
};

template<class T = int>
struct maxval {
    T x;
    maxval(T x = numeric_limits<T>::min()) : x(x) {}
    T operator() () const { return x; }
    maxval operator+ (const maxval& b) const { return max(x, b.x); }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, q;
    cin >> n >> q;
    
    segtree<maxval<ll>> hit(n+1);
    segtree<minval<ll>> lot(n+1);
    vector<int> a(n);  
    vector<ll> z(n+1);

    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    hit.set(0, 0);
    lot.set(0, 0);
    for (int i=0; i<n; i++) {
        int b;
        cin >> b;
        z[i+1] = z[i] + b - a[i];
        hit.set(i+1, z[i+1]);
        lot.set(i+1, z[i+1]);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        if (z[l] != z[r]) {
            cout << "-1\n";
        } else if (lot(l, r)() < z[l]) {
            cout << "-1\n";
        } else {
            cout << hit(l, r)() - z[l] << '\n';
        }
    }
}