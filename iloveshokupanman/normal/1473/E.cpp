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


	struct dijkstra {

		ll N;
		vector<vector<edge>> g;
		ll s;

		vector<ll> ans;

		dijkstra(ll N0, ll s, vector<vector<edge>> g0) {//(1index0index)
			N = N0;
			g = g0;

			ans.assign(N + 1, INF);


			priority_queue<pair<ll, ll>> q;//(-)

			ans[s] = 0;
			q.push({ 0,s });

			while (!q.empty()) {
				auto x = q.top();
				q.pop();

				ll dis = -x.first;
				ll v = x.second;

				if (dis > ans[v]) { continue; }


				for (edge e : g[v]) {
					ll w = e.to;
					if (dis + e.d < ans[w]) {
						ans[w] = dis + e.d;
						q.push({ -ans[w], w });
					}
				}


			}
		}

		ll d(ll t) {//st
			return ans[t];
		}


	};


	int main() {
		ll N, M;
		cin >> N >> M;

		vector<vector<edge>> g(4 * N);
		rep(i, M) {
			ll a, b, c;
			cin >> a >> b >> c;
			a--; b--;
			rep(k, 4) {
				g[N * k + a].push_back({N * k + b,c });
				g[N * k + b].push_back({N * k + a,c });
			}
			rep(k, 2) {
				g[N * k + a].push_back({N * (k + 2) + b,2 * c });
				g[N * k + b].push_back({N * (k + 2) + a,2 * c });
			}
			rep(k, 2) {
				g[N * 2 * k + a].push_back({N * (2 * k + 1) + b,0 });
				g[N * 2 * k + b].push_back({N * (2 * k + 1) + a,0 });
			}
		}

		dijkstra dij(4 * N, 0, g);

		//rep(i, 4 * N) { cout << dij.ans[i] << endl; }
		vll ans(N);

		repn(i, N - 1) {
			ans[i] = dij.ans[3 * N + i];
		}

		for (auto e : g[0]) {
			if (e.to < N) { ans[e.to] = min(ans[e.to], e.d); }
		}
		repn(i, N - 1)cout << ans[i] << " ";
		cout << endl;
	}