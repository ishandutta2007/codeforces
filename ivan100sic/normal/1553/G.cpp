// Retired?
#include <bits/stdc++.h>
using namespace std;

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

     auto factor_small(int x) const {
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
    auto factor(T x) const {
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
};

struct union_find {
    vector<int> p;
    union_find(int n) : p(n) { iota(begin(p), end(p), 0); }
    bool operator() (int x, int y) { return e(x) == e(y); }
    int e(int x) {
        if (p[x] == x) return x;
        return p[x] = e(p[x]);
    }
    bool join(int x, int y) {
        x = e(x), y = e(y);
        if (x == y) return false;
        p[x] = y;
        return true;
    }
};

int n, q;
int a[150005];
sieve sv(1000005);
basic_string<int> e[1000005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> q;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        for (auto [p, ex] : sv.factor_small(a[i])) {
            e[p] += i;
        }
    }

    union_find uf(n);

    for (int p=2; p<1000005; p++) {
        for (int i=1; i<(int)e[p].size(); i++) {
            uf.join(e[p][i-1], e[p][i]);
        }
    }

    set<pair<int, int>> adj;

    for (int i=0; i<n; i++) {
        vector<int> pf;
        for (auto [p, ex] : sv.factor_small(a[i])) pf.push_back(p);
        for (auto [p, ex] : sv.factor_small(a[i] + 1)) pf.push_back(p);
        sort(begin(pf), end(pf));
        pf.erase(unique(begin(pf), end(pf)), end(pf));
        for (int p : pf) {
            if (e[p].empty()) continue;
            for (int q : pf) {
                if (e[q].empty()) continue;
                if (p < q) {
                    int u = uf.e(e[p][0]);
                    int v = uf.e(e[q][0]);
                    if (u > v) swap(u, v);
                    adj.insert({u, v});
                }
            }
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (uf(x, y)) {
            cout << "0\n";
        } else {
            x = uf.e(x);
            y = uf.e(y);
            if (x > y) swap(x, y);
            if (adj.count({x, y})) {
                cout << "1\n";
            } else {
                cout << "2\n";
            }
        }
    }
}