#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#include<bitset>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
#include<complex>
#include<cassert>
using namespace std;

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
const ll INF = 2e18;
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
	//ll ind;
	//ll fr;
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
typedef vector<vector<ll> > vvll;
typedef vector<vector<vector<ll> > > vvvll;

typedef vector<mint> vmint;
typedef vector<vector<mint> > vvmint;
typedef vector<vector<vector<mint> > > vvvmint;

/////////////////////////////////////



int main() {
	ll Q;
	cin >> Q;
	rep(query, Q) {
		ll N, K;
		cin >> N >> K;
		string S;
		cin >> S;

		vector<bool> s(N);
		rep(i, N)s[i] = 1-(S[i] - '0');

		vll pr(N, -1);
		rep(i, N) {
			if (i > 0)pr[i] = pr[i - 1];
			if (s[i]) { pr[i] = i; }
		}

		ll L = min(K,21);

		set<ll> st;
		ll now = 0;
		rep(i, N) {
			//cout << now << endl;
			now = now * 2 + s[i];
			if((now>>L)&1)now -= (1 << L);

			if (i >= K - 1 && (K==L||pr[i - L] <= i - K)) { st.insert(now); }
		}

		rep(x, 1 << L) {
			if (!st.count(x)) {
				cout << "YES" << endl;
				rep(i, K - L)cout << 0;
				rep(i, L)cout << ((x >> (L - 1 - i)) & 1);
				cout << endl;
				break;
			}
			if (x == (1 << L) - 1) { cout << "NO" << endl; }
		}
	}
}