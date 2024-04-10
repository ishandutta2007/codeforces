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
using namespace std;

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 4000001;
const long double eps = 1E-14;

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

//////////////////////////////////////

void op(vll& a, ll i) {
	ll x = a[i];
	ll y = a[i + 1];
	ll z = a[i + 2];
	a[i] = z;
	a[i + 1] = x;
	a[i + 2] = y;
}

vll ans(vll b) {
	ll N = b.size()-1;
	vll ret;

	while (1) {
		ll t = 0;
		repn(i,N){
			if (i != b[i]) { t = i; break; }
		}

		if (t == N - 1) { return{ -1 }; }
		if (t == 0) { return ret; }

		ll u = t;
		for (ll i = t + 1; i <= N; i++) {
			if (b[i]==t) { u = i; break; }
		}

		//cout << t << u << endl;
		
		if (u - t >= 2) { ll x = u - 2; op(b, x); ret.push_back(x); }
		else { ll x = t; op(b, x); ret.push_back(x); }
	}
}


int main() {
	ll T;
	cin >> T;
	repn(t, T) {
		ll N;
		cin >> N;
		vll a(N + 1);
		repn(i, N) cin >> a[i];

		vector<pair<ll, ll>> p(N + 1);
		repn(i, N) p[i] = { a[i],i };

		sort(++p.begin(), p.end());

		vll b(N + 1);
		repn(i, N) b[p[i].second]=i;

		//repn(i, N) cout << b[i] << " ";
		//cout << endl;

		vll ret = ans(b);
		if (ret.size() == 1 && ret[0] == -1) {
			ll t = 0;
			repn(i, N - 1) {
				if (p[i].first == p[i + 1].first) { t = i; }
			}
			if (t == 0) { cout << -1 << endl; continue; }
			swap(b[p[t].second], b[p[t + 1].second]);
			//repn(i, N) cout << b[i] << " ";

			ret = ans(b);
		}

		cout << ret.size() << endl;
		rep(i, ret.size()) { cout << ret[i] << " "; }
		cout << endl;
	}
}