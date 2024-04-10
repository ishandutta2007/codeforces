#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<int m>
struct modint {

	unsigned x;

	modint() : x(0) {}

	modint(long long arg) {
		arg %= m;
		if (arg < 0) {
			x = arg + m;
		} else {
			x = arg;
		}
	}	

	modint& operator+= (const modint& other) {
		x += other.x;
		if (x >= m) {
			x -= m;
		}
		return *this;
	}

	modint& operator*= (const modint& other) {
		x = (x * 1ll * other.x) % m;
		return *this;
	}

	modint& operator-= (const modint& other) {
		x += m - other.x;
		if (x >= m) {
			x -= m;
		}
		return *this;
	}

	modint operator+ (const modint& other) const {
		modint tmp = *this;
		tmp += other;
		return tmp;
	}

	modint operator- (const modint& other) const {
		modint tmp = *this;
		tmp -= other;
		return tmp;
	}

	modint operator* (const modint& other) const {
		modint tmp = *this;
		tmp *= other;
		return tmp;
	}

	explicit operator int () const {
		return x;
	}

	modint& operator++ () {
		++x;
		if (x == m) {
			x = 0;
		}
		return *this;
	}

	modint& operator-- () {
		if (x == 0) {
			x = m-1;
		} else {
			--x;
		}
		return *this;
	}

	modint operator++ (int) {
		modint tmp = *this;
		++*this;
		return tmp;
	}

	modint operator-- (int) {
		modint tmp = *this;
		--*this;
		return tmp;
	}

	bool operator== (const modint& other) const {
		return x == other.x;
	}

	bool operator!= (const modint& other) const {
		return x != other.x;
	}

	template<class T>
	modint operator^ (T arg) const {
		if (arg == 0) {
			return 1;
		}
		if (arg == 1) {
			return x;
		}
		auto t = *this ^ (arg >> 1);
		t *= t;
		if (arg & 1) {
			t *= *this;
		}
		return t;
	}

	modint inv() const {
		return *this ^ (m-2);
	}
};

const int MOD = 998244353;
typedef modint<MOD> mint;

ll rut(ll x) {
	ll l = 1, r = 1'500'000'000ll;

	ll o = 0;

	while (l <= r) {
		ll m = (l+r) >> 1;
		if (m*m <= x) {
			o = m;
			l = m+1;
		} else {
			r = m-1;
		}
	}

	return o;
}

ll cbrt(ll x) {
	ll l = 1, r = 1'300'000ll;

	ll o = 0;

	while (l <= r) {
		ll m = (l+r) >> 1;
		if (m*m*m <= x) {
			o = m;
			l = m+1;
		} else {
			r = m-1;
		}
	}

	return o;
}

ll qrt(ll x) {
	ll l = 1, r = 38'000ll;

	ll o = 0;

	while (l <= r) {
		ll m = (l+r) >> 1;
		if (m*m*m*m <= x) {
			o = m;
			l = m+1;
		} else {
			r = m-1;
		}
	}

	return o;
}

int n;
ll a[505];
ll aorig[505];

map<ll, int> mp;

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	// nadjemo cetvrte korene
	for (int i=1; i<=n; i++) {
		ll y = qrt(a[i]);
		if (y*y*y*y == a[i]) {
			mp[y] += 4;
			a[i] = -1;
		}
	}

	for (int i=1; i<=n; i++)
		if (a[i] != -1) {
			// kub koreni?
			ll y = cbrt(a[i]);
			if (y*y*y == a[i]) {
				mp[y] += 3;
				a[i] = -1;
			}
		}

	for (int i=1; i<=n; i++)
		if (a[i] != -1) {
			// kvadratni koreni?
			ll y = rut(a[i]);
			if (y*y == a[i]) {
				mp[y] += 2;
				a[i] = -1;
			}
		}

	// ostali su proizvod dva razlicita
	// uradimo parcijalu fakt. pomocu nzd

	for (int i=1; i<=n; i++) {
		if (a[i] == -1)
			continue;

		for (int j=1; j<=n; j++) {
			if (a[j] == -1)
				continue;

			ll g = gcd(a[i], a[j]);
			if (g != a[i] && g != a[j] && g != 1) {
				// to je faktor
				a[i] /= g;
				a[j] /= g;
				mp[g] += 2;
				mp[a[i]] += 1;
				mp[a[j]] += 1;
				a[i] = -1;
				a[j] = -1;

				break;
			}
		}
	}

	mint sol = 1;

	// probaj i sa nadjenim prostim faktorima
	queue<ll> pf;
	for (auto p : mp) {
		pf.push(p.first);
	}

	while (pf.size()) {

		ll x = pf.front(); pf.pop();

		for (int i=1; i<=n; i++) {
			if (a[i] == -1)
				continue;

			if (a[i] % x == 0) {
				mp[x]++;
				mp[a[i] / x]++;
				pf.push(a[i] / x);
				a[i] = -1;
			}
		}
	}

	// sve sto ostane su pq

	for (auto p : mp) {
		sol *= p.second + 1;
	}

	map<ll, int> occ;
	for (int i=1; i<=n; i++)
		if (a[i] != -1)
			occ[a[i]]++;

	for (auto p : occ) {
		sol *= (p.second + 1) * (p.second + 1);
	}

	cout << (int)sol << '\n' << flush;
}