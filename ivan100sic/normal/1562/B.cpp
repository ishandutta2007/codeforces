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
} sv(1005);

// ugly
int gx;

int notprime(int x) {
    gx = x;
    return x == 1 || sv.f[x] != x;
}

int notprime(int x, int y) {
    return notprime(10*x + y);
}

int notprime(int x, int y, int z) {
    return notprime(100*x + 10*y + z);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    sieve s(1000);
    int t;
    cin >> t;
    while (t--) {
        int n, f = 0, x = 0;
        string s;
        cin >> n >> s;
        for (int i=0; i<n && !f; i++) {
            if (notprime(s[i] - '0')) {
                f = 1;
                x = s[i] - '0';
            }
        }

        for (int i=0; i<n && !f; i++) {
            for (int j=i+1; j<n && !f; j++) {
                if (notprime(s[i] - '0', s[j] - '0')) {
                    f = 2;
                }
            }
        }

        for (int i=0; i<n && !f; i++) {
            for (int j=i+1; j<n && !f; j++) {
                for (int k=j+1; k<n && !f; k++) {
                    if (notprime(s[i] - '0', s[j] - '0', s[k] - '0')) {
                        f = 3;
                    }
                }
            }
        }

        cout << f << '\n' << gx << '\n';
    }
}