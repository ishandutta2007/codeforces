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

const int MAXN = 53;
int can[MAXN][MAXN], edge[MAXN][MAXN], n, m;
int deg[MAXN];

int used[MAXN], pa[MAXN];
void dfs(int v) {
	used[v] = 1;
	for(int u = 0; u < n; ++u) {
		if(edge[v][u] && can[v][u] && !used[u]) {
			pa[u] = v;
			dfs(u);
		}
	}
}

int push(int v, int u) {
	if(v == u) return 0;
	if((deg[v] - 1) * (deg[v] - 1) + (deg[u] + 1) * (deg[u] + 1) >= deg[v] * deg[v] + deg[u] * deg[u]) return 0;
	memset(used, 0, sizeof(used));
	memset(pa, NIL, sizeof(pa));
	dfs(v);
	if(pa[u] == NIL) return 0;
#ifdef __LOCAL
	cout << "@pushing " << v + 1 << " -> " << u + 1 << '\n';
#endif
	for(int t = u; t != v; t = pa[t]) {
		++deg[t];
		--deg[pa[t]];
		edge[pa[t]][t] ^= 1;
		edge[t][pa[t]] ^= 1;
	}

	return 1;
}

int calc() {
	int rez = 0;
	for(int i = 0; i < n; ++i) rez += deg[i] * deg[i];
	return rez;
}

void solve() {
	cin >> n >> m;
	for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) can[i][j] = i != j;
	for(int i = 0; i < m; ++i) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		can[v][u] = 0;
		can[u][v] = 0;
		edge[v][u] = 1;
	}

	for(int i = 0; i < n; ++i) for(int j = 0; j < i; ++j) edge[i][j] |= can[i][j]; 
	for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) deg[i] += edge[i][j];

	int ch = 1;
	while(ch) {
		ch = 0;
		for(int v = 0; v < n; ++v) {
			for(int u = 0; u < n; ++u) {
				ch |= push(v, u);
			}
		}
	}
	
#ifdef __LOCAL
	for(int i = 0; i < n; ++i) cout << "@D[" << i + 1 << "]=" << deg[i] << '\n';
#endif

	for(int i = 0; i < n; ++i) {
		string row(n, '0');
		for(int j = 0; j < n; ++j) row[j] += edge[i][j];
		cout << row << '\n';
	}
}

int main() {
	fast_io();
	solve();

	return 0;
}