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

int a[500005], b[500005], c[500005];
int n;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	sieve s(10'000'005);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		auto f = s.factor_small(a[i]);
		if (f.size() == 1) {
			b[i] = c[i] = -1;
		} else {
			auto [x, cr] = f[0];
			int xc = 1;
			while (cr--) {
				xc *= x;
			}
			b[i] = xc;
			c[i] = a[i] / b[i];
		}
	}

	for (int i=0; i<n; i++) cout << b[i] << " \n"[i == n-1];
	for (int i=0; i<n; i++) cout << c[i] << " \n"[i == n-1];
}