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
} sv(100005);

enum num_kind {
    one,
    prime,
    prime_square,
    prime_power,
    other
};

num_kind get_num_kind(ll x) {
    if (x == 1) return one;
    auto s = sv.factor(x);
    if (s.size() == 1) {
        if (s[0].second == 1) return prime;
        if (s[0].second == 2) return prime_square;
        return prime_power;
    } else {
        return other;
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    for (int tc : ra(0, t)) {
        ll x, d, b = 0;
        cin >> x >> d;
        ll t = x;
        while (t % d == 0) {
            t /= d;
            b++;
        }

        bool ans = false;

        auto tk = get_num_kind(t);
        auto dk = get_num_kind(d);

        if (b >= 2) {
            // t can be split among two baskets 
            ans |= tk != one && tk != prime;
        }

        if (b >= 3) {
            if (tk == one) {
                // d d d or dx dy
                ans |= dk != prime;
            }
            
            if (tk == prime) {
                // dt d d
                ans |= dk == other; // dtx dy (appropriate powers)
                if (d % t == 0) {
                    // dtt dtt
                    ans |= dk == prime_power; // 3 or more
                } else {
                    ans = dk != prime;
                }
            }
        }

        if (b >= 4) {
            // you can have dt d d d
            // or dt dx dy where xy = d since d is not a prime
            ans |= dk != prime;
        }

        cout << (ans ? "YES\n" : "NO\n");
    }
}