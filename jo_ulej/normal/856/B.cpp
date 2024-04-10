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

const int MAXN = (int)2e6;
const int A = 26;

struct Node {
	int go[A];
	int link, pa, pch;

	Node(): link(NIL), pa(NIL), pch(NIL) {
		memset(go, NIL, sizeof(go));
	}
};

vector<Node> T;
vector<int> G[MAXN];
int take[MAXN], leave[MAXN], used[MAXN];

int alloc() {
	T.emplace_back();
	return len(T) - 1;
}

int n, root;

void calc(int v) {
	if(T[v].pa == root) {
		T[v].link = root;
	} else if(T[v].pa != NIL) {
		int p = T[v].pa;

		if(T[p].link != NIL) {
			T[v].link = T[T[p].link].go[T[v].pch];
		}
	}

	if(T[v].link != NIL) {
		int u = T[v].link;
		G[v].push_back(u);
		G[u].push_back(v);
	}

	for(int c = 0; c < A; ++c) {
		int u = T[v].go[c];

		if(u != NIL) {
			calc(u);
		}
	}
}

void dfs(int v) {
	used[v] = 1;
	take[v] = 1;
	leave[v] = 0;

	for(auto& u: G[v]) {
		if(!used[u]) {
			dfs(u);

			take[v] += leave[u];
			leave[v] += max(take[u], leave[u]);
		}
	}
}

void solve() {
	cin >> n;
	root = alloc();

	for(int i = 0; i < n; ++i) {
		auto S = fetch<string>();
		int cur = root;

		for(auto& ch: S) {
			int code = ch - 'a';
			int nxt = T[cur].go[code];

			if(nxt == NIL) {
				T[cur].go[code] = alloc();
				nxt = T[cur].go[code];

				T[nxt].pa = cur;
				T[nxt].pch = code;
			}

			cur = nxt;
		}
	}

	calc(root);
	int answ = 0;

	for(int i = root; i < len(T); ++i) {
		if(!used[i]) {
			dfs(i);
			
			if(i == root) {
				answ += leave[i];
			} else {
				answ += max(take[i], leave[i]);
			}
		}
	}

	cout << answ << '\n';
}

int main() {
	fast_io();

	int T = fetch<int>(); 

	while(T--) {
		solve();
	}

	return 0;
}