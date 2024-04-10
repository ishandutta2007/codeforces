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

struct maxint {
    int x;
    maxint(int x=-1e9) : x(x) {}
    maxint operator+ (const maxint& b) const {
        return maxint(max(x, b.x));
    }
};

using drvo = segtree<maxint>;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<drvo> ol(n+5, drvo(n+5));
        int sol = 1e9;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            int g = i+1-x;
            if (g >= 0) {
                int z = 1;
                for (int i=1; i<x; i++) {
                    z = max(z, ol[i](0, g+1).x + 1);
                }
                ol[x].add(g, z);
                if (z >= k) {
                    sol = min(sol, g);
                }
            }
        }
        if (sol > 5e8) sol = -1;
        cout << sol << '\n';
    }
}