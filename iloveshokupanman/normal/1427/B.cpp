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
	ll T;
	cin >> T;
	repn(t, T) {
		ll N, K;
		cin >> N >> K;
		string S;
		cin >> S;

		vll ren(N, 1e9);
		repn(i, N-1) {
			if (S[i - 1] == 'W') { ren[i] = 0; }
			else { ren[i] = min(ren[i - 1] + 1, 1e9); }
			//cout << ren[i] << endl;
		}

		vll v;
		rep(i, N) {
			if (S[i] == 'W' && ren[i] > 0 && ren[i] < 1e9) { v.push_back(ren[i]); }
		}
		sort(v.begin(), v.end());

		ll ans = 0;
		ll count = 0;
		rep(i, N) {
			if (S[i] == 'W') {
				if (i == 0 || S[i - 1] == 'L') { ans++; }
				else { ans += 2; }
				count++;
			}
		}
		//cout << ans <<" ";

		if (count + K >= N) { cout << 2 * N - 1 << endl; }
		else if (count == 0) { cout << max(0,2 * K - 1) << endl; }
		else {
			//rep(i, v.size()) { cout << v[i] << " "; }
			//cout << endl;

			rep(i, v.size()) {
				if (K < v[i]) { break; }
				ans += v[i] * 2 + 1;
				K -= v[i];
			}
			ans += 2 * K;
			cout << ans << endl;
		}


	}
}