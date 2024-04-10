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

sieve sv(1005);

int ask(int h, int w, int i1, int j1, int i2, int j2, int rev) {
	if (rev) {
		swap(h, w);
		swap(i1, j1);
		swap(i2, j2);
	}

	cout << "? " << h << ' ' << w << ' ' << i1 << ' ' << j1 << ' ' << i2 << ' ' << j2 << '\n' << flush;
	int r;
	cin >> r;
	return r;
}

int resi(int n, int m, int rev) {
	auto v = sv.factor_small(n);
	int c = 1;
	for (auto [p, e] : v) {
		if (p == 2) {
			int d = 1;
			for (int i=1; i<=e; i++) {
				if (ask(n/d/2, m, 1, 1, n/d/2+1, 1, rev)) {
					d *= 2;
				} else {
					break;
				}
			}
			c *= d;
		} else {
			int d = 1;
			for (int i=1; i<=e; i++) {
				int t = n/d/p*((p-1)/2);
				if (ask(t, m, 1, 1, t+1, 1, rev) && ask(t, m, 1, 1, n+1-t, 1, rev)) {
					d *= p;
				} else {
					break;
				}
			}
			c *= d;
		}
	}

	return c;
}

int dl(int x) {
	int y = 0;
	for (int i=1; i<=x; i++) {
		if (x % i == 0) {
			y++;
		}
	}
	return y;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

	int n, m;
  cin >> n >> m;
	int x = resi(n, m, 0);
	int y = resi(m, n, 1);

	cout << "! " << dl(x) * dl(y) << '\n' << flush;
}