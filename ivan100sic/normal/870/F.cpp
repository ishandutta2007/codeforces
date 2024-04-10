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

ll g[10000005];
int q[10000005], n;

/*
dist 1: svi parovi kojima je gcd > 1: accumulate(g+2, g+n+1, 0ll);
dist 2: ??
dist 3: svi parovi prost broj p :: broj ciji je najmanji prost faktor q tkd q <= n/2 i pq > n
  dvaput brojis sve parove (p, q) gde je pq > n i max(p, q) <= n/2, oba su prosta
dist inf: svi parovi koji sadrze bar jedan prost broj veci od n/2
*/

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	sieve s(n+1);
	for (int i=1; i<=n; i++)
		g[i] = (n/i)*(n/i-1ll) / 2;
	for (int i=n; i>=1; i--)
		for (int j=2*i; j<=n; j+=i)
			g[i] -= g[j];

	ll d1 = accumulate(g+2, g+n+1, 0ll);

	for (int i=2; i<=n; i++)
		q[s.f[i]]++;
	for (int i=1; i<=n; i++)
		q[i] += q[i-1];

	ll exc = 0;
	for (int p : s.primes)
		if (p*2 > n)
			exc++;

	ll dinf = exc * (n-2) - exc * (exc - 1) / 2;

	ll d3 = 0;

	int ql = s.primes.size() - 1, pid = 0;
	for (int p : s.primes) {
		while (ql > 0 && p * 1ll * s.primes[ql - 1] > n)
			ql--;
		int qqll = s.primes[ql];
		int qqhh = n/2;
		if (2*p <= n) {
			// cerr << p << ' ' << qqll << ' ' << qqhh << '\n';
			d3 += max(0, q[qqhh] - q[qqll-1]);
			d3 -= max(0, pid - ql);
			if (p*1ll*p > n)
				d3--;
		}
		pid++;
	}

	ll d2 = (n-1ll)*(n-2ll) / 2 - d1 - dinf - d3;

	// cerr << d1 << '\n';
	// cerr << d2 << '\n';
	// cerr << d3 << '\n';
	// cerr << dinf << '\n';

	cout << d1+2*d2+3*d3 << '\n';
}