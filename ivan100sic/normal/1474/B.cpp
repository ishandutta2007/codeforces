// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

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

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  sieve s(30005);
	vector<ll> a(30005, 1e18);

  for (ll p : s.primes) {
		// p^3?
		a[p-1] = min(a[p-1], p*p*p);

    for (ll q : s.primes) {
			if (p < q) {
				ll g = min({p-1, q-p, p*q-q});
				a[g] = min(a[g], p*q);
			}
    }
  }

	for (int i=30003; i>=0; i--) {
		a[i] = min(a[i], a[i+1]);
	}

	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		cout << a[x] << '\n';
	}
}