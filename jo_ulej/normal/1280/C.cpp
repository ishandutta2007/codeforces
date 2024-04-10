#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <sstream>
#include <bitset>
#include <cassert>
#include <fstream>
#include <queue>

#define len(X) ((int)(X).size())

#ifdef __LOCAL
	#define DBG(X) cout << #X << "=" << (X) << '\n';
	#define SAY(X) cout << (X) << '\n';
#else
	#define DBG(X)
	#define SAY(X)
#endif
 
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e11);

const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }

const int MAXN = (int)2e5 + 777;
vector<pair<int, ll>> g[MAXN];
int n;
ll depth[MAXN];
int sz[MAXN];
ll B = 0;
vector<int> centroids;

void prepare(int v, int p) {
	sz[v] = 1;

	for(auto& ed: g[v]) {
		int u = ed.first;
		ll w = ed.second;

		if(u != p) {
			depth[u] = depth[v] + w;
			prepare(u, v);
			sz[v] += sz[u];
		}
	}
}

void find(int v, int p) {
	int mxsubtree = 0;

	for(auto& ed: g[v]) {
		int u = ed.first;

		if(u != p) {
			mxsubtree = max(mxsubtree, sz[u]);
		}
	}

	mxsubtree = max(mxsubtree, n - sz[v]);

	if(2 * mxsubtree <= n) {
		centroids.push_back(v);
	}

	for(auto& ed: g[v]) {
		int u = ed.first;

		if(u != p) {
			find(u, v);
		}
	}
}

ll calc_B(int v, int p, ll pref) {
	ll rez = pref;

	for(auto& ed: g[v]) {
		int u = ed.first;
		ll  w = ed.second;

		if(u != p) {
			rez += calc_B(u, v, pref + w);
		}
	}

	return rez;
}

ll dp[MAXN], sum[MAXN];

void calc_A(int v, int p) {
	ll sm = 0;

	for(auto& ed: g[v]) {
		int u = ed.first;

		if(u != p) {
			calc_A(u, v);
			sm += dp[u];
		}
	}

	dp[v] = LL_INF;
	sum[v] = sm;
	vector<ll> vals;

	for(auto& ed: g[v]) {
		int u = ed.first;
		ll w = ed.second;

		if(u != p) {
			vals.push_back(-dp[u] + w + sum[u]);
		}
	}

	sort(vals.begin(), vals.end());
	ll pref = 0;

	for(int i = 0; i < len(vals); ++i) {
		pref += vals[i];

		if((i + 1) & 1) {
			dp[v] = min(dp[v], sm + pref);
		} else {
			sum[v] = min(sum[v], sm + pref);
		}
	}
}

void solve() {
	cin >> n;
	n *= 2;
	B = 0;

	centroids.clear();
	for(int i = 0; i < n; ++i) {
		g[i].clear();
		depth[i] = 0;
		sz[i] = 0;

		sum[i] = dp[i] = 0;
	}

	for(int i = 0; i < n - 1; ++i) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		ll  w = fetch<ll>();

		g[v].emplace_back(u, w);
		g[u].emplace_back(v, w);
	}

	const int root = 0;
	prepare(root, NIL);
	find(root, NIL);

	for(auto& c: centroids) {
		ll local = calc_B(c, NIL, 0);
		DBG(local);
		B = max(B, local);
	}

	calc_A(root, NIL);

#ifdef __LOCAL
	for(int i = 0; i < n; ++i) {
		cout << "dp[" << i + 1 << "]=" << dp[i] << '\n';
		cout << "sum[" << i + 1 << "]=" << sum[i] << '\n';
	}
#endif

	cout << dp[root] << ' ' << B << '\n';
}

int main() {
	fast_io();

	int T = fetch<int>();

	while(T--) {
		solve();
	}

	return 0;
}