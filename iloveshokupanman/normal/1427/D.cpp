#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
#include<complex>
#include<cassert>
using namespace std;

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e19;
const ll MOD = 998244353;
const ll MAX = 4000001;
const long double eps = 1E-7;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

struct edge {
	ll ind;
	ll fr;
	ll to;
	ll d;
};

class mint {
	long long x;
public:
	mint(long long x = 0) : x((x% MOD + MOD) % MOD) {}
	mint operator-() const {
		return mint(-x);
	}
	mint& operator+=(const mint& a) {
		if ((x += a.x) >= MOD) x -= MOD;
		return *this;
	}
	mint& operator-=(const mint& a) {
		if ((x += MOD - a.x) >= MOD) x -= MOD;
		return *this;
	}
	mint& operator*=(const  mint& a) {
		(x *= a.x) %= MOD;
		return *this;
	}
	mint operator+(const mint& a) const {
		mint res(*this);
		return res += a;
	}
	mint operator-(const mint& a) const {
		mint res(*this);
		return res -= a;
	}
	mint operator*(const mint& a) const {
		mint res(*this);
		return res *= a;
	}

	mint pow(ll t) const {
		if (!t) return 1;
		mint a = pow(t >> 1);
		a *= a;
		if (t & 1) a *= *this;
		return a;
	}

	// for prime MOD
	mint inv() const {
		return pow(MOD - 2);
	}
	mint& operator/=(const mint& a) {
		return (*this) *= a.inv();
	}
	mint operator/(const mint& a) const {
		mint res(*this);
		return res /= a;
	}

	friend ostream& operator<<(ostream& os, const mint& m) {
		os << m.x;
		return os;
	}
};

mint pw(mint a, ll b) {
	if (b == 0) { return 1; }
	mint ret = pw(a, b >> 1);
	ret *= ret;
	if (b & 1) { ret *= a; }
	return ret;
}

typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;

typedef vector<mint> vmint;
typedef vector<vector<mint>> vvmint;
typedef vector<vector<vector<mint>>> vvvmint;

/////////////////////////////////////

int main() {
	ll N;
	cin >> N;
	vll c(N + 1);
	repn(i, N)cin >> c[i];

	vector<pair<pair<ll, ll>,ll>> ans;

	while (1) {
		ll t = -1;
		ll x = -1;
		ll y = -1;

		repn(i, N-1) {
			repn(j, N) {
				if (c[j] == i) { y = j; }
				if (c[j] == i + 1) { x = j; }
			}
			if (y > x) { t = i; break; }
		}

		if (t == -1) { break; }

		vll d(5);
		d[1] = x - 1;
		d[2] = x;
		while (c[d[2] + 1] == c[d[2]] + 1) { d[2]++; }
		d[3] = y;
		d[4] = N;
		
		ans.push_back({ {d[1],d[2]},d[3] });

		vll nc(1, 0);
		for (ll j = 3; j >= 0; j--) {
			for (ll k = d[j] + 1; k <= d[j + 1]; k++) {
				nc.push_back(c[k]);
			}
		}
		repn(i, N)c[i] = nc[i];
	}

	cout << ans.size() << endl;
	rep(j, ans.size()) {
		ll x = ans[j].first.first;
		ll y = ans[j].first.second;
		ll z = ans[j].second;

		vll v;
		if (x > 0) { v.push_back(x); }
		if (y > x) { v.push_back(y-x); }
		if (z > y) { v.push_back(z - y); }
		if (N > z) { v.push_back(N - z); }
		cout << v.size() << " ";
		rep(i, v.size())cout << v[i] << " ";
		cout << endl;
	}
}