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
const ll MOD = 998244353;
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
int main() {
	ll N;
	cin >> N;

	vvll g(N, vll(N, 0));
	rep(i, N) {
		string s;
		cin >> s;
		rep(j, N) g[i][j] = s[j] - '0';
	}

	vvvll dp(1 << N);


	repn(b, (1 << N) - 1) {
		ll pp = 0;
		rep(i, N) { if ((b >> i)&1){pp++; } }

		dp[b].assign(1 << (pp - 1), vll(N, 0));

		if (pp == 1) {
			rep(i, N) { if ((b >> i) & 1) { dp[b][0][i] = 1;} }
			continue;
		}

		rep(i, N)rep(j,N) {
			if (i == j) { continue; }
			if (!((b >> i) & 1)) { continue; }
			if (!((b >> j) & 1)) { continue; }

			ll x = b ^ (1 << i);

			//cout << i <<" "<< j <<" "<< g[i][j] << endl;

			rep(k, 1 << (pp - 2)) {
				if (g[i][j] == 1) { dp[b][2 * k + 1][i] += dp[x][k][j]; }
				else { dp[b][2 * k][i] += dp[x][k][j]; }

				//cout << i << " " << j << dp[b][2 * k + g[i][j]][i] << endl;
			}

		}

		//rep(j, N)rep(k, 1 << (pp - 1)) { cout << b << " " << k << " " << j <<" "<<dp[b][k][j]<< endl; }

	}

	vll ans(1 << (N - 1), 0);

	rep(i, (1 << (N - 1))) {
		rep(j, N) {
			ans[i] += dp[(1 << N) - 1][i][j];
		}
		cout << ans[i] << " ";
	}
	cout << endl;
}