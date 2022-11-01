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

const int MAXN = (int)2e5 + 777;
vector<int> g[MAXN], tree[MAXN];
int deg[MAXN], in_tree[MAXN], used[MAXN], root[MAXN], pa[MAXN];
int n, m;

ll w[MAXN], answ = 0;

ll dfs(int v) {
	used[v] = 1;
	ll rez = 0;

	for(auto& u: tree[v]) {
		rez = max(rez, dfs(u));
	}

	rez += w[v];
	return rez;
}

int found[MAXN];

void visit(int v) {
	found[v] = 1;

	for(auto& u: g[v]) {
		if(!found[u]) {
			visit(u);
		}
	}
}

int V = 0, E = 0;

void count(int v) {
	used[v] = 1;
	++V;
	E += len(g[v]);

	for(auto& u: g[v]) {
		if(!used[u]) {
			count(u);
		}
	}
}

ll dfs2(int v, int p) {
	ll rez = 0;

	for(auto& u: g[v]) {
		if(u != p) {
			rez = max(rez, dfs2(u, v));
		}
	}

	rez += w[v];
	return rez;
}

void solve() {
	cin >> n >> m;
	memset(pa, NIL, sizeof(pa));

	for(int i = 0; i < n; ++i) {
		cin >> w[i];
	}

	for(int i = 0; i < m; ++i) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;

		g[v].push_back(u);
		g[u].push_back(v);

		++deg[v];
		++deg[u];
	}

	int s = fetch<int>() - 1;
	visit(s);

	for(int i = 0; i < n; ++i) {
		if(!found[i]) {
			w[i] = 0;
		}

		root[i] = 1;
	}

	count(s); E /= 2;
	memset(used, 0, sizeof(used));
	DBG(V); DBG(E);

	if(E == V - 1) {
		cout << dfs2(s, NIL) << '\n';
		return;
	}

	set<pii> setik;

	for(int i = 0; i < n; ++i) {
		setik.emplace(deg[i], i);
	}

	while(!setik.empty()) {
		auto fst = setik.begin();
		int v = fst->second;
		setik.erase(fst);

		if(deg[v] > 1) {
			break;
		}

		for(auto& u: g[v]) {
			if(in_tree[u]) {
				tree[v].push_back(u);
				root[u] = 0;
				pa[u] = v;
			} else {
				setik.erase(make_pair(deg[u], u));
				--deg[u];
				setik.emplace(deg[u], u);
			}
		}

		in_tree[v] = 1;
	}

	while(s != NIL && in_tree[s]) {
		answ += w[s];
		w[s] = 0;

		s = pa[s];	
	}

	ll mx = 0;

	for(int i = 0; i < n; ++i) {
		if(!used[i]) {
			if(in_tree[i]) {
				if(root[i]) {
					mx = max(mx, dfs(i));
				}
			} else {
				answ += w[i];
			}
		}
	}

	answ += mx;
	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}