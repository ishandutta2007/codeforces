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
} sv(20'000'005);

int fsc[20000005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    for (int p : sv.primes) {
        for (int j=p; j<20000005; j+=p) {
            fsc[j]++;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        ll c, d, x;
        cin >> c >> d >> x;
        ll sol = 0;

        for (ll q=1; q*q<=x; q++) {
            if (q*q == x) {
                if ((d * q + x) % (c * q) == 0) sol += 1 << fsc[(d * q + x) / (c * q)];
                break;
            } else if (x % q == 0) {
                if ((d * q + x) % (c * q) == 0) sol += 1 << fsc[(d * q + x) / (c * q)];
                ll t = q;
                q = x / q;
                if ((d * q + x) % (c * q) == 0) sol += 1 << fsc[(d * q + x) / (c * q)];
                q = t;
            }
        }

        cout << sol << '\n';
    }
}