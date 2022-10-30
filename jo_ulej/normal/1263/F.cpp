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
const ll  LL_INF  = (ll)(2e18);

const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }

const int MAXN = 4007;
vector<int> g[MAXN];
int L[MAXN], R[MAXN], cost[MAXN];
int n, A, B;
int dp[MAXN];

bool upd(int& x, int y) {
	if(y > x) {
		x = y;
		return true;
	} else {
		return false;
	}
}

void init() {
	for(int i = 0; i < MAXN; ++i) {
		L[i] = INT_INF;
		R[i] = -INT_INF;
		dp[i] = -INT_INF;
	}

	dp[0] = 0;
}

void dfs(int v, int pa) {
	cost[v] += (pa != NIL);

	for(auto& u: g[v]) {
		if(u != pa) {
			dfs(u, v);

			L[v] = min(L[v], L[u]);
			R[v] = max(R[v], R[u]);
			cost[v] += cost[u];
		}
	}
}

void solve() {
	cin >> n;
	init();

	cin >> A;

	for(int i = 1; i < A; ++i) {
		int j = fetch<int>() - 1;
		g[i].push_back(j);
		g[j].push_back(i);
	}

	for(int i = 0; i < n; ++i) {
		int leaf = fetch<int>() - 1;
		L[leaf] = R[leaf] = i;
	}

	cin >> B;

	for(int i = 1; i < B; ++i) {
		int j = fetch<int>() - 1;
		g[i + A].push_back(j + A);
		g[j + A].push_back(i + A);
	}

	for(int i = 0; i < n; ++i) {
		int leaf = fetch<int>() - 1;
		L[leaf + A] = R[leaf + A] = i;
	}

	dfs(0, NIL); dfs(A, NIL);

	int sz = A + B;
	for(int v = 0; v < sz; ++v) {
		DBG(v); DBG(L[v]); DBG(R[v]); DBG(cost[v]);
	}

	for(int i = 0; i < n; ++i) {
		if(dp[i] != -INT_INF) {
			for(int v = 0; v < sz; ++v) {
				if(i <= L[v]) {
					upd(dp[R[v] + 1], dp[i] + cost[v]); 
				}
			}
		}
	}

	cout << dp[n] << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}