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
long long iv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}

int main() {
	ll x;
	cin >> x;

	vector<pair<ll, ll>> ans;
	vll op;

	while (x > 1) {
		ll c = 0;
		while ((1ull<<c) < x) {
			c++;
		}
		//cout << c << endl;
		ll y = iv(x, 1ull<<c);
		//cout << y << endl;
		rep(i, c) {
			ans.push_back({ x << i,x << i });
			op.push_back(0);
		}

		ll now = x;
		repn(i, c-1) {
			if ((y >> i) & 1) {
				ans.push_back({ now,x << i });
				op.push_back(0);
				now += x << i;
			}
		}

		//cout << y << " " << now << endl;

		ans.push_back({ x * y,x });
		op.push_back(0);

		ans.push_back({ x * y,x * y + x });
		op.push_back(1);

		now = (x * y) ^ (x * y + x);

		ans.push_back({ now,x });
		op.push_back(1);
		now = now ^ x;

		//cout << now << endl;

		while (now*2 < (1ull << c)) {
			ans.push_back({ now,now });
			op.push_back(0);
			now *= 2;
		}

		ans.push_back({ now,x });
		op.push_back(1);
		x = now ^ x;
		
		//cout << x <<"!"<< endl;
	}

	cout << ans.size() << endl;
	rep(i, ans.size()) {
		cout << ans[i].first << " ";
		if (op[i] == 0) { cout << '+'<<" "; }
		else { cout << '^' << " "; }
		cout << ans[i].second << endl;
	}

	
}