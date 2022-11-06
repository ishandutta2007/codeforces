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

/////////////////////////////////////
ll N;
vvll g;
vll t;
vll h;

pair<ll, ll> dfs(ll u, ll v) {
	ll ret1 = 0;
	ll ret2 = 0;

	ll in = 0;
	ll out = 0;
	vector<pair<ll, pair<ll, ll>>> dp;//in,out
	for (ll w : g[v]) {
		if (u == w) { continue; }
		auto p = dfs(v, w);

		if (h[v] < h[w]) {
			out++;
			ret1 += p.first;
			ret2 += p.first;
		}
		else if (h[v] > h[w]) {
			in++;
			ret1 += p.second;
			ret2 += p.second;
		}
		else {
			dp.push_back({ p.first - p.second,{p.first,p.second} });
		}
	}

	ll M = dp.size();
	sort(dp.begin(), dp.end());

	if (u != 0 && h[u] > h[v]) { ret1 = INF; }
	else {
		ll iin = in;
		ll oout = out;
		if (u != 0) { iin++; }

		ll sum = 0;
		rep(i, M) {
			iin++;
			sum += dp[i].second.second;
		}
		ll x = sum;
		ll now = sum + t[v] * max(iin, oout);
		rep(i, M) {
			x -= dp[i].second.second;
			x += dp[i].second.first;
			iin--;
			oout++;
			now = min(now, x + t[v] * max(iin, oout));
		}

		ret1 += now;
	}

	if (u != 0 && h[u] < h[v]) { ret2 = INF; }
	else {
		ll iin = in;
		ll oout = out;
		if (u != 0) { oout++; }

		ll sum = 0;
		rep(i, M) {
			iin++;
			sum += dp[i].second.second;
		}
		ll x = sum;
		ll now = sum + t[v] * max(iin, oout);
		rep(i, M) {
			x -= dp[i].second.second;
			x += dp[i].second.first;
			iin--;
			oout++;
			now = min(now, x + t[v] * max(iin, oout));
		}

		ret2 += now;
	}

	//cout << v << ret1 << ret2 << endl;

	return { ret1,ret2 };
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	g.resize(N + 1);
	t.resize(N + 1);
	h.resize(N + 1);
	repn(i, N)cin >> t[i];
	repn(i, N)cin >> h[i];
	repn(i, N - 1) {
		ll a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	pair<ll, ll> ans = dfs(0, 1);
	cout << ans.first << endl;
}