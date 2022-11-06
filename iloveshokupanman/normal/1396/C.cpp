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

/////////////////////////////////////


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll N, d;
	vll r(4);
	cin >> N >> r[1] >> r[2] >> r[3] >> d;
	vll a(N + 1);
	repn(i, N)cin >> a[i];

	vll mo(N + 1), dmo(N + 1);
	repn(i, N) {
		dmo[i] = r[1] * a[i] + r[3];
		mo[i] = min(r[2] + r[1], r[1] * a[i] + r[1] + r[1]);

		//cout << i << " " << dmo[i] << " " << mo[i] << endl;
	}

	vvll dp(N + 1, vll(3, INF));
	dp[1][0] = dmo[1];
	dp[1][1] = mo[1] + d;

	for(ll i=2;i<=N;i++) {
		if (i < N)dp[i][0] = min(dp[i - 1][0] + dmo[i], dp[i - 1][1] + dmo[i] + d);
		else { dp[i][0] = min(dp[i - 1][0] + dmo[i], dp[i - 1][1] + dmo[i]); }
		dp[i][0] = min(dp[i][0], dp[i - 1][2] + dmo[i]);

		dp[i][1] = min(dp[i - 1][0] + mo[i] + d, dp[i - 1][2] + mo[i] + d);
		if (i == N) { dp[i][1] += d; }

		dp[i][2] = dp[i - 1][1] + mo[i] + d;

		//cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
	}

	ll ans = min(dp[N][0], min(dp[N][1], dp[N][2]));
	cout << ans+d*(N-1) << endl;
}