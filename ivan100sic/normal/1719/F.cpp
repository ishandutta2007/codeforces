// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct sieve {
    const int maxn;
    vector<int> f, primes;

    sieve(int maxn) : maxn(maxn), f(maxn) {
        for (int i=2; i<maxn; i++) {
            if (f[i] == 0) {
                f[i] = i;
                primes.push_back(i);
            }

            for (int p : primes) {
                if (p > f[i] || i * p >= maxn) {
                    break;
                }

                f[i*p] = p;
            }
        }
    }

     vector<pair<int, int>> factor_small(int x) const {
        vector<pair<int, int>> v;
        while (x > 1) {
            int p = f[x], c = 0;
            while (x % p == 0) {
                x /= p;
                c++;
            }
            v.emplace_back(p, c);
        }
        return v;
    }

    template<class T>
    vector<pair<T, int>> factor(T x) const {
        vector<pair<T, int>> v;
        for (int p : primes) {
            if ((ll)p*p > x) {
                break;
            }

            if (x % p == 0) {
                int c = 0;
                while (x % p == 0) {
                    x /= p;
                    c++;
                }
                v.emplace_back(p, c);
            }
        }

        if (x > 1) {
            v.emplace_back(x, 1);
        }

        return v;
    }
} sv(200005);

vector<int> fp(int n) {
    vector<int> f;
    for (auto [p, e] : sv.factor_small(n)) {
        f.push_back(p);
    }
    return f;
}

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

using maxsegtree = segtree<maxval<ll>>;
const int inf = 1123123123;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);

        for (int& x : a) cin >> x;

        auto f = fp(n);
        int k = ssize(f);

        vector<maxsegtree> st;
        for (int i : ra(0, k)) {
            st.emplace_back(n / f[i]);
        }

        auto ans = [&] {
            ll sol = 0;
            for (int i : ra(0, k)) {
                sol = max(sol, st[i].a[1]() * n / f[i]);
            }
            return sol;
        };

        for (int i : ra(0, k)) {
            for (int j : ra(0, n / f[i])) {
                ll val = 0;
                for (int t : ra(0, f[i])) {
                    val += a[t*(n/f[i]) + j];
                }
                st[i].set(j, val);
            }
        }

        cout << ans() << '\n';

        while (q--) {
            int p, x;
            cin >> p >> x;
            p--;

            ll delta = x - a[p];
            for (int i : ra(0, k)) {
                int loc = p % (n / f[i]);
                ll oldval = st[i].a[st[i].maxn + loc]();
                st[i].set(loc, oldval + delta);
            }

            a[p] += delta;

            cout << ans() << '\n';
        }
    }
    
}