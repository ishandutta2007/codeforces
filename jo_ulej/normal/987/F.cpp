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
	#define DBG(X) cout << #X << "=" << (X) << endl;
#else
	#define DBG(X)
	#define endl '\n'
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
template<typename T> inline void goodbye(const T& val) { cout << val << endl; exit(0); }

const int MAXN = 22;
const int MAXV = 2 * (1 << MAXN) + 228;

/* vector<int> g[MAXV]; */
int exists[MAXV];
int n, m, full_mask;

/*void add_edge(int v, int u) {
	g[v].push_back(u);
}*/

int Q[MAXV], head = 0;
int used[MAXV];

void bfs(int src) {
	head = 0;
	used[src] = 1;
	Q[head++] = src;


	/*for(auto& u: g[v]) {
		if(exists[u] && !used[u]) {
			dfs(u);
		}
	}*/

	for(int ptr = 0; ptr < head; ++ptr) {
		int v = Q[ptr];
		vector<int> us;

		if(v < (1 << n)) {
			us.push_back((1 << n) + (v ^ full_mask));
		} else {
			int without = v - (1 << n);
			us.push_back(without);

			for(int j = 0; j < n; ++j) {
				int bit = 1 << j;

				if(without & bit) {
					us.push_back((1 << n) + (without ^ bit));
				}
			}
		}

		for(auto& u: us) {
			if(exists[u] && !used[u]) {
				used[u] = 1;
				Q[head++] = u;
			}
		}
	}
}

void solve() {
	cin >> n >> m;

	for(int i = 0; i < m; ++i) {
		int value;
		cin >> value;

		exists[value] = 1;
	}

	full_mask = (1 << n) - 1;

	for(int i = 0; i < (1 << n); ++i) {
		exists[(1 << n) + i] = 1;
	}

	/*for(int i = 0; i < (1 << n); ++i) {
		add_edge(i, (1 << n) + i ^ full_mask);
		add_edge((1 << n) + i, i);
	}

	for(int i = 0; i < (1 << n); ++i) {
		for(int j = 0; j < n; ++j) {
			int bit = 1 << j;

			if(i & bit) {
				add_edge((1 << n) + i, (1 << n) + (i ^ bit));
			}
		}
	}*/

	int answ = 0;

	for(int v = 0; v < (1 << n); ++v) {
		if(exists[v] && !used[v]) {
			bfs(v);
			++answ;
		}
	}

	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}