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
const ll INF = 1e18+1e18;
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
	ll N, M;
	cin >> N >> M;
	vvll A(N + 1, vll(M + 1, 0));
	repn(i, N)repn(j, M)cin >> A[i][j];

	vll R(N + 1, 0), C(M + 1, 0);

	repn(i, N)repn(j, M)R[i] = max(R[i], A[i][j]);
	repn(i, N)repn(j, M)C[j] = max(C[j], A[i][j]);

	ll K = N * M;
	vll isr(K + 1, 0), isc(K + 1, 0);
	repn(i, N)isr[R[i]] = 1;
	repn(j, M)isc[C[j]] = 1;

	//repn(i, K)cout << isr[i] << endl;
	//repn(i, K)cout << isc[i] << endl;

	vvll ans(N + 2, vll(M + 2, 0));
	ll posx = 0;
	ll posy = 0;
	queue<ll> qx, qy;

	vll dx = { 1,0,-1,0 };
	vll dy = { 0,1,0,-1 };

	for (ll k = K; k >= 1; k--) {
		ll adx, ady;
		if (isr[k] && isc[k]) {
			posx++;
			posy++;
			adx = posx;
			ady = posy;
		}
		else if (isr[k]) {
			posx++;
			adx = posx;
			ady = posy;
		}
		else if (isc[k]) {
			posy++;
			adx = posx;
			ady = posy;
		}
		else {
			adx = qx.front();
			qx.pop();
			ady = qy.front();
			qy.pop();
		}

		//cout << k << adx << ady << endl;

		ans[adx][ady] = k;

		rep(j, 4) {
			ll xx = adx + dx[j];
			ll yy = ady + dy[j];
			if (xx <= 0 || xx > N || yy <= 0 || yy > M) { continue; }
			if (ans[xx][yy] != 0) { continue; }


			ll count = 0;
			rep(l, 4) {
				if (ans[xx + dx[l]][yy + dy[l]] != 0) { count++; }
			}
			if (count == 2) { qx.push(xx); qy.push(yy); }
		}

	}

	repn(i, N) {
		repn(j, M)cout << ans[i][j] << " ";
		cout << endl;
	}
}