// Retired?
#include <bits/stdc++.h>
using namespace std;

/*
the number of different algorithms used in this problem is just disgusting
*/

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
} sito(33333);

int n, m, p, g;
vector<pair<int, int>> fp1;
vector<int> dp1;

int a[10005];

int pw(int x, int k) {
	if (k == 0) return 1;
	int y = pw(x, k >> 1);
	y = y * 1ll * y % p;
	if (k & 1) {
		y = y * 1ll * x % p;
	}
	return y;
}

int primitive_root() {
	for (int x=1;; x++) {
		int ok = 1;
		for (auto [y, _] : fp1) {
			if (pw(x, (p-1)/y) == 1) {
				ok = 0;
			}
		}
		if (ok) {
			return x;
		}
	}
	return -1;
}

const int H = 2000005;
const int S = 500;
pair<int, int> pws[H];

void bsgs() {
	int z = 1, w = pw(g, S);
	for (int i=0; i<H; i++) {
		pws[i] = {z, i*S};
		z = 1ll * z * w % p;
	}
	sort(pws, pws+H);
}

int dlog(int x) {
	int z = x;
	for (int i=0; i<S; i++) {
		auto pos = lower_bound(pws, pws+H, pair(z, 0)) - pws;
		if (pos < H && pws[pos].first == z) {
			return (pws[pos].second + S*(p - 1ll) - i) % (p-1);
		}
		z = 1ll * z * g % p;
	}
	return -1;
}

void calc_dp1() {
	set<int> s;
	for (int x=1; x*x<=p-1; x++) {
		if ((p-1) % x == 0) {
			s.insert(x);
			s.insert((p-1)/x);
		}
	}
	dp1 = vector<int>(s.begin(), s.end());
}

bool mark[12312];

void dodaj(int x) {
	int i = 0;
	for (int d : dp1) {
		if (d % x == 0) {
			mark[i] = 1;
		}
		i++;
	}
}

int eulerphi(int x) {
	int u = x;
	for (auto [p, _] : fp1) {
		if (x % p == 0) {
			u = u/p*(p-1);
		}
	}
	return u;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m >> p;
	fp1 = sito.factor(p-1);
	g = primitive_root();
	bsgs();
	calc_dp1();
	for (int i=0; i<n; i++)
		cin >> a[i];

	int gcdb = 0;
	for (int j=0; j<m; j++) {
		int x;
		cin >> x;
		gcdb = gcd(gcdb, x);
	}

	for (int i=0; i<n; i++) {
		int la = dlog(a[i]);
		dodaj(gcd(la*1ll*gcdb, p-1));
	}

	int sol = 0;

	for (int i=0; i<(int)dp1.size(); i++) {
		if (mark[i]) {
			sol += eulerphi((p-1) / dp1[i]);
		}
	}

	cout << sol << '\n';
}