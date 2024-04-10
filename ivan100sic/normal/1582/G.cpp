// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class T = int>
struct minval {
    T x;
    minval(T x = numeric_limits<T>::max()) : x(x) {}
    T operator() () const { return x; }
    minval operator+ (const minval& b) const { return min(x, b.x); }
    minval& operator+= (const minval& b) { x = min(x, b.x); return *this; }
};

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

struct sieve {
    const int maxn;
    vector<int> f, primes, ord;

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

        ord.resize(maxn);
        for (int i=0; i<ssize(primes); i++) {
            ord[primes[i]] = i;
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
            v.emplace_back(ord[p], c);
        }
        return v;
    }
} sv(1000001);

using minint = minval<int>;

struct slow_prefix {
    deque<minint> a;
    minint global;
    int base;

    void add(int p, minint v) {
        if (p >= base && p < base + ssize(a)) {
            a[p - base] += v;
            while (p+1 < base + ssize(a)) {
                a.pop_back();
            }
        } else if (p < base) {
            base = p;
            global += v;
            a = {};
        } else {
            while (p >= base + ssize(a)) {
                auto b = a.empty() ? minint{} : a.back();
                a.emplace_back(b);
            }
            a.back() += v;
        }
    }

    minint operator() (int p) {
        if (p >= base && p < base + ssize(a)) {
            return global + a[p - base];
        } else if (p < base) {
            return {};
        } else {
            if (a.empty()) return global;
            return global + a.back();
        }
    }
};

int n;
int a[1000005];
string b;
int sume[80000];
vector<slow_prefix> iseg(80000);
segtree<minint> allseg(80000);

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i : ra(0, n)) cin >> a[i];
    cin >> b;

    for (int i=0; i<80000; i++) {
        allseg.set(i, n);
    }

    ll sol = 0;
    for (int i=n-1; i>=0; i--) {
        for (auto [p, e] : sv.factor_small(a[i])) {
            if (b[i] == '/') e *= -1;
            int stara = -sume[p];
            sume[p] += e;
            iseg[p].add(stara, i);
            allseg.set(p, iseg[p](-sume[p]-1) + n);
        }
        int le = allseg(0, 80000)();
        sol += le - i;
    }

    cout << sol << '\n';
}