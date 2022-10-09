#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// n <= 10^14
inline ll mulmod(ll x, ll y, ll n) {
	ll z = 0;
	z += y * (x & 0xffffll);
	z += y * ((x >> 16) & 0xffffll) % n * 65536 % n;
	z += y * ((x >> 32) & 0xffffll) % n * 65536 % n * 65536 % n;
	return z % n;
}

ll pw(ll x, ll y, ll n) {
	if (y == 0)
		return 1;

	auto r = pw(x, y >> 1ll, n);
	r = mulmod(r, r, n);
	if (y & 1)
		r = mulmod(r, x, n);
	return r;
}

template<class T>
T gcd(T a, T b) {
	T t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

const int SITO_MAX = 10'000'000ll;

int f[SITO_MAX+1];
vector<int> prosti;

struct sito {
	sito() {
		for (int i=2; i<=SITO_MAX; i++) {
			if (f[i] == 0) {
				f[i] = i;
				prosti.push_back(i);
			}
			int j = 0;
			while (j < (int)prosti.size()) {
				if (prosti[j] > f[i]) {
					break;
				}
				int x = i * prosti[j];
				if (x > SITO_MAX) {
					break;
				}
				f[x] = prosti[j];
				j++;
			}
		}
	}
} sito_obj_983431;

typedef vector<pair<ll, int>> vpli;

vpli factor_small(ll x) {
	vpli v;
	while (x > 1) {
		int p = f[x];
		int c = 0;
		while (x % p == 0) {
			x /= p;
			c++;
		}
		v.push_back({p, c});
	}
	return v;
}

vpli factor_large(ll x) {
	vpli v;
	for (int p : prosti) {
		if (x % p == 0) {
			int c = 0;
			while (x % p == 0) {
				x /= p;
				c++;
			}
			v.push_back({p, c});
		}			
	}

	if (x > 1) {
		v.push_back({x, 1});
	}
	return v;
}

map<ll, vpli> factor_cache;

vpli factor(ll x) {
	if (factor_cache.count(x))
		return factor_cache[x];

	if (x <= SITO_MAX)
		return factor_cache[x] = factor_small(x);
	else
		return factor_cache[x] = factor_large(x);
}

void divisors_impl(const vpli& v, vector<ll>& r, int i, ll p) {
	if (i == (int)v.size()) {
		r.push_back(p);
		return;
	}

	for (int j=0; j<=v[i].second; j++) {
		divisors_impl(v, r, i+1, p);
		p *= v[i].first; // ub but who cares
	}
}

vector<ll> divisors(const vpli& v) {
	vector<ll> r;
	divisors_impl(v, r, 0, 1);
	return r;
}

ll pomnozi(vpli v) {
	ll p = 1;
	for (auto e : v)
		for (int i=0; i<e.second; i++)
			p *= e.first;
	return p;
}

ll eulerphi(ll x) {
	auto v = factor(x);
	ll p = 1;
	for (auto e : v) {
		p *= e.first - 1;
		for (int i=1; i<e.second; i++)
			p *= e.first;
	}
	return p;
}

map<ll, ll> phicache;
map<ll, ll> ord;

void sredi(vpli& v) {
	int j = 0;
	for (int i=0; i<(int)v.size(); i++) {
		if (v[i].second > 0)
			v[j++] = v[i];
	}
	v.resize(j);
}

vpli oduzmi(vpli u, vpli v) {
	int i = 0;
	for (int j=0; j<(int)v.size(); j++) {
		while (i < (int)u.size() && u[i].first != v[j].first)
			i++;
		if (i < (int)u.size()) {
			u[i].second -= v[j].second;
		}
	}
	sredi(u);
	return u;
}

void find_orders(ll m, vpli mf, ll phim, vpli phimf, ll x) {
	if (m == 1)
		return;

	if (ord.count(m))
		return;

	ll& o = ord[m];

	phicache[m] = phim;

	auto divs = divisors(phimf);
	for (ll y : divs) {
		if (pw(x, y, m) == 1) {
			// y je order za ovo
			o = y;
			break;
		}
	}

	for (auto e : mf) {
		ll p = e.first;
		if (m / p % p == 0) {
			find_orders(
				m/p, oduzmi(mf, factor(p)),
				phim/p, oduzmi(phimf, factor(p)), x);
		} else {
			find_orders(
				m/p, oduzmi(mf, factor(p)),
				phim/(p-1), oduzmi(phimf, factor(p-1)), x);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll m, x;
	cin >> m >> x;
	find_orders(m, factor(m), eulerphi(m), factor(eulerphi(m)), x);

	ll sol = 0;

	for (auto p : ord) {
		// cerr << p.first << ' ' << p.second << ' ';
		// cerr << phicache[p.first] << ' ' << eulerphi(p.first) << '\n';
		sol += phicache[p.first] / p.second;
	}

	cout << sol+1 << '\n';
}