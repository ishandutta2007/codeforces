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

const int H = 1000000;

struct term {
	int a[9], s, c;

	term operator+ (const term& b) const {
		term t;
		int x[18];
		t.s = set_union(a, a+s, b.a, b.a+b.s, x) - x;
		t.s = min(t.s, 9);
		for (int i=0; i<t.s; i++)
			t.a[i] = x[i];
		t.c = c + b.c;
		return t;
	}

	term& operator+= (const term& b) {
		return *this = *this + b;
	}

	void an(int x) {
		if (s < 9) {
			int f = lower_bound(a, a+s, x) - a;
			if (f < s && a[f] == x)
				return;
			a[s++] = x;
			rotate(a+f, a+s-1, a+s);
		}
	}

	void ae(int x, int y) {
		an(x);
		an(y);
		c++;
	}
};

int n, k;
int a[5005];
term c[H+5];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);

	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			c[a[j] - a[i]].ae(i, j);
		}
	}

	sieve sv(H+1);

	for (int p : sv.primes) {
		for (int x=H/p*p; x; x-=p) {
			c[x/p] += c[x];
		}
	}

	// grana, cvorova
	set<pair<int, int>> ok = {{0, 0}};
	if (k >= 1) {
		ok.emplace(1, 2);
	}

	if (k >= 2) {
		ok.emplace(2, 4);
		ok.emplace(3, 3);
	}

	if (k >= 3) {
		ok.emplace(3, 6); // 2 2 2
		ok.emplace(4, 5); // 3 2
		ok.emplace(6, 4); // 4
	}

	if (k >= 4) {
		ok.emplace(4, 8); // 2 2 2 2
		ok.emplace(5, 7); // 3 2 2
		ok.emplace(6, 6); // 3 3
		ok.emplace(7, 6); // 4 2
		ok.emplace(10, 5); // 5
	}

	for (int d=1; d<=H+1; d++) {
		int gr = c[d].c;
		int cv = c[d].s;
		if (ok.count({gr, cv})) {
			cout << d << '\n';
			return 0;
		}
	}
}