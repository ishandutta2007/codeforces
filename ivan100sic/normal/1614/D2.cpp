// Retired?
#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif

#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const int H = 20000000;

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
} sv(H+1);

struct state {
    int cnt, divs;
    ll dp;
};

state a[H+5];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n;
    for (int i : ra(0, n)) {
        int x;
        cin >> x;
        a[x].cnt++;
    }

    for (int i : ra(1, H+1)) {
        for (int j=i; j<=H; j+=i) {
            a[i].divs += a[j].cnt;
        }
    }

    a[1].dp = n;
    for (int i : ra(1, H+1)) {
        for (int p : sv.primes) {
            int j = p*i;
            if (j > H) break;
            a[j].dp = max(a[j].dp, a[i].dp + a[j].divs * ll(j-i));
        }
    }

    ll sol = 0;
    for (int i : ra(0, H)) sol = max(sol, a[i+1].dp);
    cout << sol << '\n';
}