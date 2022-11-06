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


int main() {
	ll N, K;
	cin >> N >> K;
	vll t(N + 1), a(N + 1), b(N + 1);
	repn(i, N) cin >> t[i] >> a[i] >> b[i];

	vll both, al, bob;
	repn(i, N) {
		if (a[i] == 1 && b[i] == 1) { both.push_back(t[i]); }
		else if (a[i] == 1) { al.push_back(t[i]); }
		else if (b[i] == 1) { bob.push_back(t[i]); }
	}
	sort(both.begin(), both.end());
	sort(al.begin(), al.end());
	sort(bob.begin(), bob.end());

	ll X = min(al.size(), bob.size());
	ll Y = both.size();
	vll one(X);
	rep(i, X)one[i] = al[i] + bob[i];

	vll ro(X + 1, 0), rb(Y + 1, 0);
	repn(i, X)ro[i] = ro[i - 1] + one[i - 1];
	repn(i, Y)rb[i] = rb[i - 1] + both[i - 1];

	ll ans = INF;
	rep(i, X + 1) {
		ll j = K - i;
		if (j<0||j > Y) { continue; }
		ll now = ro[i] + rb[j];
		ans = min(now, ans);
	}

	if (ans == INF) { ans = -1; }
	cout << ans << endl;
}