// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<int m>
struct modint {
    unsigned x;

    modint() : x(0) {}
    modint(long long arg) : x((arg %= m) < 0 ? arg + m : arg) {}

    modint operator+ (const modint& b) const {
        auto t = *this; t.x = (t.x += b.x) >= m ? t.x-m : t.x; return t;
    }

    modint operator- (const modint& b) const {
        auto t = *this; t.x = (t.x += m-b.x) >= m ? t.x-m : t.x; return t;
    }

    modint operator* (const modint& b) const {
        auto t = *this; t.x = ll(t.x) * b.x % m; return t;
    }

    modint operator/ (const modint& b) const {
        return *this * b.inv();
    }

    template<class T> modint operator^ (T n) const {
        modint t;
        if (n == 0) return t.x = 1, t;
        if (n == 1) return t.x = x, t;
        t = *this ^ (n >> 1); t *= t;
        return n & 1 ? *this * t : t;
    }

    modint& operator+= (const modint& b) { return *this = *this + b; }
    modint& operator-= (const modint& b) { return *this = *this - b; }
    modint& operator*= (const modint& b) { return *this = *this * b; }
    modint& operator/= (const modint& b) { return *this = *this / b; }
    modint& operator++ () { if (++x == m) x = 0; return *this; }
    modint& operator-- () { if (x-- == 0) x = m-1; return *this; }
    modint operator++ (int) { modint tmp = *this; ++*this; return tmp; }
    modint operator-- (int) { modint tmp = *this; --*this; return tmp; }
    bool operator== (const modint& other) const { return x == other.x; }
    bool operator!= (const modint& other) const { return x != other.x; }
    int operator() () const { return x; }
    template<class T> modint operator^= (T n) { return *this = *this ^ n; }
    modint inv() const { return *this ^ (m-2); }
};

const int mod = 1000 * 1000 * 1000 + 7;
typedef modint<mod> mint;

template<class T = mint>
struct binomial {
    vector<T> f, finv;

    binomial(int n) : f(n), finv(n) {
        f[0] = finv[0] = 1;
        for (int i=1; i<n; i++) {
            f[i] = f[i-1] * i;
            finv[i] = T(1) / f[i];
        }
    }

    T mix(int a, int b) {
        if (a < 0 || b < 0)
            return 0;
        return f[a+b] * finv[a] * finv[b];
    }

    T choose(int n, int k) {
        return mix(n-k, k);
    }
};


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
} sv(1000005);

int n;
int a[1000005];

void zero() {
    cout << "0\n";
    exit(0);
}

ull whc[1000005];

ull w_hash(int x) {
    if (whc[x] != -1ull) return whc[x];

    ull w = 0;
    for (auto [p, _a] : sv.factor_small(x)) {
        if (2*p > n) {
            // ignore
        } else {
            w = w * 437618471638743ull + n/p;
        }
    }

    return whc[x] = w;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    memset(whc, 255, sizeof(whc));

    cin >> n;
    const auto N = ra(1, n+1);
    for (int i : N) cin >> a[i];

    int sqrtn = 1;
    while (sqrtn * sqrtn <= n) sqrtn++;
    sqrtn--;

    map<ull, set<int>> mp;
    vector<map<int, map<ull, set<int>>>> teeth(sqrtn + 2);

    for (int i : N) {
        auto fs = sv.factor_small(i);
        auto target = &mp;
        if (fs.size()) {
            // tooth part
            auto [p, _a] = fs.back();
            if (p > sqrtn && 2*p <= n) {
                int tooth_class = n / p;
                target = &teeth[tooth_class][p];
            }
        }

        target->operator[](w_hash(i)).insert(i);
    }

    binomial bk(n+2);
    mint sol = 1;
    // non-teeth
    for (auto [k, g] : mp) {
        int c = 0;
        for (int i : g) {
            if (a[i] && !g.contains(a[i])) {
                zero();
            } else if (!a[i]) {
                c++;
            }
        }
        sol *= bk.f[c];
    }

    // teeth
    for (int class_id : ra(1, sqrtn + 2)) {
        auto& tooth_class = teeth[class_id]; // tooth_class is a class
        set<int> used_allegiances;
        int unused_rows = 0;
        for (auto& [_k, tmap] : tooth_class) { // tmap is a row
            int row_allegiance = 0;
            mint row_sol = 1;
            
            for (auto& [_k, v] : tmap) { // v is one iso-group in a row

                set<ull> v_hashed;
                for (int x : v) {
                    v_hashed.insert(w_hash(x));
                }

                int c = 0;
                for (int i : v) {
                    if (a[i]) {
                        if (a[i] == 1) {
                            // not allowed
                            zero();
                        }

                        int p = sv.factor_small(a[i]).back().first;
                        if (n / p != class_id) {
                            // in some other class, not allowed
                            zero();
                        }

                        if (row_allegiance && p != row_allegiance) {
                            // alleg. to two different rows
                            zero();
                        }
                        row_allegiance = p;

                        if (!v_hashed.contains(w_hash(a[i]))) {
                            // wrong iso-group
                            zero();
                        }
                    } else {
                        c++;
                    }
                }
                row_sol *= bk.f[c];
            }

            if (row_allegiance) {
                if (used_allegiances.contains(row_allegiance)) {
                    // two rows have same alleg
                    zero();
                }

                used_allegiances.insert(row_allegiance);
            } else {
                unused_rows++;
            }

            sol *= row_sol;
        }

        // we can permute the unused rows in this class
        sol *= bk.f[unused_rows];
    }

    cout << sol() << '\n';
}

/*
60
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
*/