// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());
using uid = uniform_int_distribution<ll>;
using urd = uniform_real_distribution<double>;

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
} sv(200005);

bool isprime(int x) {
    return x < 3 || sv.f[x] == x;
}

struct cache {
    map<pair<int, int>, ll> c;

    ll ask(int x, int y) {
        if (x > y) swap(x, y);
        if (c.count({x, y})) {
            return c[{x, y}];
        }

        cout << "? " << x << ' ' << y << '\n' << flush;
        ll z;
        cin >> z;
        return c[{x, y}] = z;
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        cache c;
        int n;
        cin >> n;

        vector<int> idx(n);
        iota(begin(idx), end(idx), 1);
        shuffle(begin(idx), end(idx), eng);
        vector<int> sol(n+1);

        if (n >= 100) {
            int hiprime = 0;
            int hiidx = 0;
            int primec = 0;

            for (int i : idx) {
                set<int> asked;
                while ((int)asked.size() != min(n-1, 16)) {
                    int x = uid(1, n)(eng);
                    if (x == i) continue;
                    asked.insert(x);
                }

                ll g = 0;
                for (int x : asked) {
                    g = gcd(g, c.ask(i, x));
                }

                sol[i] = g;
                if (isprime(g)) {
                    if (g > hiprime) {
                        hiprime = g;
                        hiidx = i;
                    }
                    primec++;
                    if (primec == 16) {
                        break;
                    }
                }
            }

            for (int j : idx) {
                if (!sol[j]) {
                    sol[j] = c.ask(hiidx, j) / hiprime;
                }
            }
        } else if (n == 3) {
            ll x12 = c.ask(1, 2);
            ll x13 = c.ask(1, 3);
            ll x23 = c.ask(2, 3);

            ll hi = round((sqrt(1 + 4*max({x12, x13, x23})) + 1) * 0.5);
            vector<ll> a = {hi-2, hi-1, hi};

            do {
                if (lcm(a[0], a[1]) == x12 && lcm(a[0], a[2]) == x13 && lcm(a[1], a[2]) == x23) {
                    copy(begin(a), end(a), begin(sol) + 1);
                    break;
                }
            } while (next_permutation(begin(a), end(a)));

        } else {
            for (int i=1; i<=n; i++) {
                ll g = 0;
                for (int j=1; j<=n; j++) {
                    if (i == j) continue;
                    g = gcd(g, c.ask(i, j));
                }
                sol[i] = g;
            }
        }

        cout << "! ";
        for (int i=1; i<=n; i++) {
            cout << sol[i] << " \n"[i == n];
        }
        cout << flush;
    }
}