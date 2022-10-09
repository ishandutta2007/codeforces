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
} sv(2000005);

vector<pair<int, int>> fp(array<int, 3> a) {
	vector<pair<int, int>> v[3], t;
	for (int i=0; i<3; i++) {
		v[i] = sv.factor_small(a[i]);
	}

	merge(begin(v[0]), end(v[0]), begin(v[1]), end(v[1]), back_inserter(t));
	v[1] = move(t);
	t = {};
	merge(begin(v[2]), end(v[2]), begin(v[1]), end(v[1]), back_inserter(t));
	v[0] = move(t);
	t = {};
	for (auto [p, e] : v[0]) {
		if (t.size() && t.back().first == p) {
			t.back().second += e;
		} else {
			t.emplace_back(p, e);
		}
	}
	return t;
}

template<class F>
void divisors(const vector<pair<int, int>>& v, F f, ll p=1, int idx=0) {
	if (idx == (int)v.size()) {
		f(p);
		return;
	}

	divisors(v, f, p, idx+1);
	for (int i=1; i<=v[idx].second; i++) {
		p *= v[idx].first;
		divisors(v, f, p, idx+1);
	}
}

ll count_divs_leq(const vector<pair<int, int>>& v, ll n) {
	ll z = 0;
	divisors(v, [&](ll x) { z += x <= n; });
	return z;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;

		ll n = 1ll*n1*n2*n3;

		int m1, m2, m3;
		cin >> m1 >> m2 >> m3;

		ll m = 1ll*m1*m2*m3;

		int s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		s3 *= 2;

		ll s = 1ll*s1*s2*s3;

		auto vs = fp({s1, s2, s3});
		auto vn = fp({n1, n2, n3});

		// drugi potez (ukljucujuci i cosak)
		ll sol = count_divs_leq(vs, n);

		// cerr << "base = " << sol << '\n';

		// prvi potez
		if (s % n == 0) {
			sol += m;
		} else {
			// brut (za svaki slucaj)
			// for (int i=1; i<=m; i++) {
			// 	if (s % gcd(i, n) == 0) {
			// 		sol++;
			// 	}
			// }

			ll g = gcd(n, s);
			vector<tuple<int, int, ll>> vg(vn.size());
			ll gt = g;
			for (int i=0; i<(int)vn.size(); i++) {
				vg[i] = {vn[i].first, 0, 1};
				while (gt % vn[i].first == 0) {
					get<1>(vg[i])++;
					get<2>(vg[i]) *= vn[i].first;
					gt /= vn[i].first;
				}
			}

			int good_masks = 0;
			for (int i=0; i<(int)vn.size(); i++) {
				if (get<1>(vg[i]) == vn[i].second) {
					good_masks |= 1 << i;
				}
			}

			for (int mask=0; mask<(1<<vg.size()); mask++) {
				if ((mask & good_masks) != good_masks) continue;
				ll p=1, sgn=1;
				for (int i=0; i<(int)vg.size(); i++) {
					if (get<1>(vg[i]) == vn[i].second) {
						continue;
					}

					if (mask & (1 << i)) {
						p *= get<0>(vg[i]) * get<2>(vg[i]);
						sgn *= -1;
					}
				}

				// cerr << "add " << m << "/" << p << " with sgn = " << sgn << '\n';
				sol += m/p*sgn;
			}


		}

		cout << sol << '\n';
  }
}