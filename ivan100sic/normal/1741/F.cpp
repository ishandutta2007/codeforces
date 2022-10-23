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

template<class T = int>
struct maxval {
    T x;
    maxval(T x = numeric_limits<T>::min()) : x(x) {}
    T operator() () const { return x; }
    maxval operator+ (const maxval& b) const { return max(x, b.x); }
    maxval& operator+= (const maxval& b) { x = max(x, b.x); return *this; }
};

struct seg {
    int l, r, c, i;

    bool operator< (const seg& b) const {
        return r < b.r;
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<seg> a(n);

        for (int i : ra(0, n)) {
            int l, r, c;
            cin >> l >> r >> c;
            c--;
            a[i] = {l, r, c, i};
        }

        R::sort(a, less<seg>{});

        vector<int> sol(n, 1012012012);
        
        auto go = [&] {
            segtree<maxval<int>> st(n, -1012012012);

            for (auto [l, r, c, i] : a) {
                int q = (st(0, c) + st(c+1, n))();

                if (q >= l) {
                    sol[i] = 0;
                } else {
                    sol[i] = min(sol[i], l-q);
                }

                st.add(c, r);
            }
        };

        go();

        R::reverse(a);
        for (auto& [l, r, c, i] : a) {
            r = 1123123123 - r;
            l = 1123123123 - l;
            swap(l, r);
        }

        go();

        for (int i : ra(0, n)) cout << sol[i] << " \n"[i == n-1];
    }
}