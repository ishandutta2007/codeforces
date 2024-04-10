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
vector<int> g[MAXN], answ;
int n;
int depth[MAXN], mxdepth[MAXN], pa[MAXN];

void dfs(int v) {
	mxdepth[v] = depth[v];

	for(auto& u: g[v]) {
		if(u != pa[v]) {
			pa[u] = v;
			depth[u] = depth[v] + 1;
			dfs(u);

			mxdepth[v] = max(mxdepth[v], mxdepth[u]);
		}
	}
}

void root(int v) {
	depth[v] = 0;
	pa[v] = NIL;

	dfs(v);
	int last = NIL, cnt_cands = 0;

	for(int cand = 0; cand < n; ++cand) {
		int leafs = 0, mn = INT_INF, mx = -INT_INF;

		for(auto& u: g[cand]) {
			if(u != pa[cand]) {
				++leafs;
				mn = min(mn, mxdepth[u]);
				mx = max(mx, mxdepth[u]);
			}
		}

		if(leafs > 0) {
			if(mx - mn > 1) {
				return;
			}

			if(mn != mx || leafs == 1 || leafs == 3) {
				++cnt_cands;
				last = cand;

				if(cnt_cands > 1) {
					return;
				}
			}
		}
	}

	if(cnt_cands != 1) {
		return;
	}

	for(int u = 0; u < n; ++u) {
		if(u == last) {
			continue;
		}

		int leafs = 0;

		for(auto& w: g[u]) {
			leafs += (w != pa[u]);
		}

		if(leafs != 0 && leafs != 2) {
			return;
		}
	}

	int mn = INT_INF, mx = -INT_INF;

	for(auto& u: g[last]) {
		if(u != pa[last]) {
			mn = min(mn, mxdepth[u]);
			mx = max(mx, mxdepth[u]);
		}
	}

	int cnt_mn = 0, cnt_mx = 0;
	int leafs = 0;

	for(auto& u: g[last]) {
		if(u != pa[last]) {
			++leafs;

			if(mxdepth[u] == mn) {
				++cnt_mn;
			} else {
				++cnt_mx;
			}
		}
	}

	if(depth[last] == mxdepth[v] - 1) {
		if(leafs != 1) {
			return;
		}
	} else {
		if(leafs != 3) {
			return;
		}

		if(cnt_mn != 2 || cnt_mx != 1) {
			return;
		}
	}

	answ.push_back(last);
}

int subtree[MAXN], mxsubtree[MAXN];
int ord[MAXN];

void calc(int v, int p) {
	subtree[v] = 1;
	mxsubtree[v] = 0;

	for(auto& u: g[v]) {
		if(u != p) {
			calc(u, v);
			subtree[v] += subtree[u];
			mxsubtree[v] = max(mxsubtree[v], subtree[u]);
		}
	}

	mxsubtree[v] = max(mxsubtree[v], n - subtree[v] - 1);
}

int dist[MAXN], ppp[MAXN];
int Q[MAXN], head = 0;

void BFS(int v) {
	for(int j = 0; j < n; ++j) {
		dist[j] = INT_INF;
	}

	dist[v] = 0;
	head = 0;
	Q[head++] = v;

	for(int j = 0; j < head; ++j) {
		int u = Q[j];

		for(auto& w: g[u]) {
			if(dist[w] > dist[u] + 1) {
				dist[w] = dist[u] + 1;
				ppp[w] = u;
				Q[head++] = w;
			}
		}
	}
}

int farthest(int v) {
	BFS(v);

	return max_element(dist, dist + n) - dist;
}

vector<int> path(int v, int u) {
	BFS(v);
	vector<int> rez;

	while(true) {
		rez.push_back(u);

		if(u == v) {
			break;
		} else {
			u = ppp[u];
		}
	}

	return rez;
}

void solve() {
	cin >> n;
	n = (1 << n) - 2;

	for(int i = 0; i < n - 1; ++i) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;

		g[v].push_back(u);
		g[u].push_back(v);
	}

	calc(0, NIL);

	for(int i = 0; i < n; ++i) {
		ord[i] = i;
	}

	sort(ord, ord + n, [&](int lhs, int rhs) {
		return mxsubtree[lhs] < mxsubtree[rhs];				
	});

	for(int j = 0; j < 4 && j < n; ++j) {
		root(ord[j]);
	}

	cout << len(answ) << '\n';
	sort(answ.begin(), answ.end());

	if(!answ.empty()) {
		for(auto& v: answ) {
			cout << v + 1 << ' ';
		}

		cout << '\n';
	}
}

int main() {
	fast_io();
	solve();

	return 0;
}