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
const ll MOD = 1000000007;
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
	cout << fixed << setprecision(10);
	ll T;
	cin >> T;

	repn(t, T) {
		ll N;
		long double L;
		cin >> N >> L;

		vector<long double> a(N + 2, 0);
		repn(i, N)cin >> a[i];
		a[N + 1] = L;

		long double l = 0;
		long double r = L;

		long double tt = 0;

		while (r - l > eps) {
			
			long double m = (r + l) / 2.0;

			//cout << m << endl;

			long double t1 = 0;
			long double t2 = 0;

			repn(i, N + 1) {
				if (a[i] > m) { t1 += (m - a[i - 1]) / (long double)i; break; }
				t1 += (a[i] - a[i - 1]) / (long double)i;
			}
			for (ll i = N; i >= 0; i--) {
				if (a[i] < m) { t2 += (a[i + 1] - m) / (long double)(N + 1 - i); break; }
				t2 += (a[i + 1] - a[i]) / (long double)(N + 1 - i);
			}

			tt = t1;

			//cout << t1 <<" "<< t2 << endl;

			if (t2 > t1) { l = m; }
			else { r = m; }
		}

		cout << tt << endl;
	}
}