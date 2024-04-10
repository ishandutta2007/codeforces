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
const double eps = 1E-18;

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
ll N;
vector<vector<ll>> g;
vector<ll> A, B, C;

vector<ll> Amn;

void dfs(ll u, ll v) {
	Amn[v] = min(Amn[u], A[v]);

	for (ll w : g[v]) {
		if (w == u) { continue; }
		dfs(v, w);
	}
}

pair<ll,ll> dfs2(ll u, ll v) {
	ll pos = 0;
	ll neg = 0;

	ll retsnd = 0;

	for (ll w : g[v]) {
		if (w == u) { continue; }
		auto p = dfs2(v, w);

		ll x = p.first;
		if (x > 0) { pos += x; }
		else if (x < 0) { neg += -x; }

		retsnd += p.second;
	}

	if (B[v] == 0 && C[v] == 1) { pos++; }
	else if (B[v] == 1 && C[v] == 0) { neg++; }

	retsnd += min(pos, neg) * Amn[v] * 2;

	return { pos - neg,retsnd };
}

int main() {
	cin >> N;
	A.resize(N + 1);
	B.resize(N + 1);
	C.resize(N + 1);
	repn(i, N) cin >> A[i] >> B[i] >> C[i];

	g.resize(N + 1);
	repn(i, N - 1) {
		ll u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	Amn.resize(N + 1);
	Amn[0] = INF;
	dfs(0, 1);
	//repn(i, N) cout << Amn[i] << endl << flush;

	auto p = dfs2(0, 1);
	if (p.first != 0) { cout << -1 << endl; }
	else { cout << p.second << endl; }
}