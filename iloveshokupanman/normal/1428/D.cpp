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
	vll a(N);
	rep(i, N)cin >> a[i];

	vll p(N, -1);
	set<ll> one;
	rep(i, N)if (a[i] == 1) { one.insert(i); }
	set<ll> all;
	rep(i, N)if(a[i]!=0)all.insert(i);

	rep(i, N) {
		if (a[i] != 2) { continue; }
		auto itr = one.upper_bound(i);
		if (itr == one.end()) { cout << -1 << endl; return 0; }
		ll x = *itr;
		p[i] = x;
		one.erase(x);
		all.erase(x);
	}

	rep(i, N) {
		if (a[i] != 3) { continue; }
		auto itr = all.upper_bound(i);
		if (itr == all.end()) { cout << -1 << endl; return 0; }
		ll x = *itr;
		p[i] = x;
		all.erase(x);
	}

	//rep(i, N)cout << p[i] << endl;

	vector<pair<ll, ll>> ans;

	ll t = 1;
	vll use(N, 0);
	rep(i, N) {
		if (use[i] != 0) { continue; }

		if (a[i] == 1) {
			ans.push_back({ i,t });
			t++;
			use[i] = 1;
		}

		if (a[i] == 2) {
			ans.push_back({ i,t });
			ans.push_back({ p[i],t });
			t++;
			use[i] = 1;
			use[p[i]] = 1;
		}

		if (a[i] == 3) {
			ans.push_back({ i,t });
			ans.push_back({ p[i],t });
			t++;
			use[i] = 1;
		}
	}

	cout << ans.size() << endl;
	rep(i, ans.size()) {
		cout << ans[i].second << " " << ans[i].first+1 << endl;
	}

	


}