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
#else
	#define DBG(X)
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

const int MAXN = (int)1e5 + 77;

vector<int> g[MAXN], answ, ord;
int par[MAXN], q[MAXN], depth[MAXN], max_depth[MAXN];
int n;

void prepare(int v, int p) {
	depth[v] = (p == NIL ? 0 : depth[p] + 1);
	max_depth[v] = depth[v];

	for(auto& u: g[v]) {
		if(u != p) {
			prepare(u, v);
			max_depth[v] = max(max_depth[v], max_depth[u]);
		}
	}
}

void dfs(int v, int p) {
	ord.push_back(v);
	sort(g[v].begin(), g[v].end(), [&](int v, int u) { return max_depth[v] < max_depth[u]; });

	for(auto& u: g[v]) {
		if(u != p) {
			dfs(u, v);
		}
	}
}

void solve() {
	cin >> n;

	par[0] = NIL;

	for(int i = 1; i < n; ++i) {
		int p = fetch<int>();

		g[i].push_back(p);
		g[p].push_back(i);

		par[i] = p;
	}

	prepare(0, NIL);
	dfs(0, NIL);
	//ord.resize(n);
	//iota(ord.begin(), ord.end(), 0);

	//sort(ord.begin(), ord.end(), [&](auto lhs, auto rhs) { return depth[lhs] < depth[rhs]; });
	
	DBG(ord);

	for(int i = 1; i < n; ++i) {
		q[ord[i]] = ord[i - 1];
	}

	for(int i = 1; i < n; ++i) {
		while(q[ord[i]] != par[ord[i]]) {
			answ.push_back(ord[i]);
			q[ord[i]] = par[q[ord[i]]];
		}
	}

	cout << ord << '\n';

	cout << len(answ) << '\n';
	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}