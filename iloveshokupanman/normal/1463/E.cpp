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
	ll N, K;
	cin >> N >> K;

	vll p(N + 1);
	repn(i, N)cin >> p[i];
	

	vll suc(N + 1);
	vll ac(N + 1);
	repn(i, N)ac[i] = i;

	repn(i, K) {
		ll a, b;
		cin >> a >> b;
		ac[b] = 0;
		suc[a] = b;
	}

	repn(i, N) {
		if (ac[i] == i) {
			ll now = i;
			while (suc[now] != 0) {
				now = suc[now];
				
				if (ac[now] != 0) { cout << 0 << endl; return 0; }
				ac[now] = i;
			}
		}
	}

	vvll g(N + 1);
	vll in(N + 1);
	repn(i, N) {
		if (p[i] == 0) { continue; }
		if (ac[p[i]] == ac[i]) { continue; }
		g[ac[p[i]]].push_back(ac[i]);
		in[ac[i]]++;
		//cout << i<<" "<<ac[p[i]] << " " << ac[i] << endl;
	}
	queue<ll> q;
	vll lis;
	repn(i, N) {
		if (ac[i] == i && in[i] == 0) {
			q.push(i);
			lis.push_back(i);
		}
	}
	while (!q.empty()) {
		ll x = q.front();
		q.pop();
		for (ll y: g[x]) {
			in[y]--;
			if (in[y] == 0) { q.push(y);  lis.push_back(y); }
		}
	}

	vll ans;
	vll ivans(N+1);

	for (ll x : lis) {
		ll now = x;
		while (now != 0) {
			ans.push_back(now);
			ivans[now] = ans.size();
			now = suc[now];
		}
	}

	repn(i, N) {
		if (p[i] != 0 && ivans[i] < ivans[p[i]]) { cout << 0 << endl; return 0; }
	}
	repn(i, N) {
		if(ivans[i]==0){ cout << 0 << endl; return 0; }
	}

	for (ll x : ans) { cout << x << " "; }
	cout << endl;


}