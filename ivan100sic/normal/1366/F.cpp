// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<int m>
struct modint {
	unsigned x;

	modint() : x(0) {}
	modint(long long arg) : x((arg %= m) < 0 ? arg + m : arg) {}

	modint operator+ (const modint& b) const {
		auto t = *this; t.x = (t.x += b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator- (const modint& b) const {
		auto t = *this; t.x = (t.x += m-b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator* (const modint& b) const {
		auto t = *this; t.x = ll(t.x) * b.x % m; return t;
	}

	template<class T> modint operator^ (T n) const {
		modint t;
		if (n == 0) return t.x = 1, t;
		if (n == 1) return t.x = x, t;
		t = *this ^ (n >> 1); t *= t;
		return n & 1 ? *this * t : t;
	}

	modint& operator+= (const modint& b) { return *this = *this + b; }
	modint& operator-= (const modint& b) { return *this = *this - b; }
	modint& operator*= (const modint& b) { return *this = *this * b; }
	modint& operator++ () { if (++x == m) x = 0; return *this; }
	modint& operator-- () { if (x-- == 0) x = m-1; return *this; }
	modint operator++ (int) { modint tmp = *this; ++*this; return tmp; }
	modint operator-- (int) { modint tmp = *this; --*this; return tmp; }
	bool operator== (const modint& other) const { return x == other.x; }
	bool operator!= (const modint& other) const {	return x != other.x; }
	int operator() () const { return x; }
	template<class T> modint operator^= (T n) { return *this = *this ^ n; }
	modint inv() const { return *this ^ (m-2); }
};

const int mod = 1'000'000'007;
typedef modint<mod> mint;

int n, m, q;
int u[2005], v[2005], w[2005];
ll d[2005][2005];

template<class T>
void mx(T& x, T y) {
	x = max(x, y);
}

struct slope {
	ll x = 0, y = -1e18, k = 0;

	bool operator< (const slope& b) const {
		return y - x*k < b.y - b.x*b.k;
	}
};

map<int, slope> mp;
vector<slope> vs;
ll h[2005];

ll daj(ll px) {
	ll z = 0;
	for (auto [x, y, k] : vs) {
		if (px >= x) {
			mx(z, y + k*(px - x));
		}
	}

	if (px <= n) {
		mx(z, h[px]);
	}

	return z;
}

mint solve_rek(int l, int r) {
	if (r - l < 2) {
		mint sol = 0;
		for (int i=l; i<=r; i++) {
			sol += daj(i);
		}
		return sol;
	}

	if ((r-l) % 2) {
		return solve_rek(l+1, r) + daj(l);
	}

	int m = (l+r) / 2;
	ll dl = daj(l);
	ll dr = daj(r);
	ll dm = daj(m);

	if (2*dm != dl + dr) {
		return solve_rek(l, m) + solve_rek(m+1, r);
	}

	return mint((dl+dr) / 2) * (r-l+1);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m >> q;
	for (int i=0; i<m; i++) {
		cin >> u[i] >> v[i] >> w[i];
	}

	memset(d, 224, sizeof d);
	d[0][1] = 0;

	for (int i=0; i<=n; i++) {
		for (int j=0; j<m; j++) {
			mx(d[i+1][v[j]], d[i][u[j]] + w[j]);
			mx(d[i+1][u[j]], d[i][v[j]] + w[j]);

			mx(mp[w[j]], slope{.x = i, .y = max(d[i][u[j]], d[i][v[j]]), .k = w[j]});
		}
		h[i] = *max_element(d[i]+1, d[i]+n+1);
	}

	for (auto [x, v] : mp) {
		vs.emplace_back(v);
	}

	// cerr << "debug\n";
	// ll zb = 0;
	// for (int i=1; i<=q; i++) {
	// 	ll di = daj(i);
	// 	cerr << i << ' ' << di << "\n";
	// 	zb += di;
	// }
	// cerr << "zb = " << zb << '\n';

	cout << solve_rek(1, q)() << '\n';
}