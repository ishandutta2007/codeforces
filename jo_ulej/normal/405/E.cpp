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
	#define DEBUG_OUTPUT_ENABLED 1
#else
	#define DEBUG_OUTPUT_ENABLED 0
#endif

#define dout   debug::instance
#define DBG(X) dout << #X << "=" << (X) << '\n';
#define SAY(X) dout << (X) << '\n';

using namespace std;

template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
namespace debug {
	struct DebugStream {
		private:
			bool is_first;
		public:
			DebugStream(bool _is_first): is_first(_is_first) {}
			template<typename T> DebugStream operator<<(const T& value) const {
				if(DEBUG_OUTPUT_ENABLED) {
					if(is_first) cout << "[DBG] ";
					cout << value;
				}
				return DebugStream(false);
			};
	};
	DebugStream instance(true);
};

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
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }
const int MAXN = (int)1e5 + 7;
vector<int> adj[MAXN];
int n, m;
int d[MAXN];
struct Edge {
	int from, to;
	void flip() {
		swap(from, to);
		d[from] ^= 1;
		d[to] ^= 1;
	}
	int get(int v) {
		assert(v == from || v == to);
		return from ^ to ^ v;
	}
};
Edge edges[MAXN];
int used[MAXN];
void dfsik(int v) {
	used[v] = 1;
	for(auto& id: adj[v]) {
		auto& e = edges[id];
		int u = e.get(v);
		if(used[u]) continue;
		dfsik(u);
		if(d[u]) e.flip();
	}
}
void fail() {
	cout << "No solution\n";
	exit(0);
}
void solve() {
	cin >> n >> m;
	for(int id = 0; id < m; ++id) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		edges[id].from = v;
		edges[id].to   = u;
		d[v] ^= 1;
		adj[v].push_back(id);
		adj[u].push_back(id);
	}
	if(m&1) fail();
	dfsik(0);
	for(int v = 0; v < n; ++v) {
		vector<int> U;
		for(auto& id: adj[v]) {
			auto& e = edges[id];
			int u = e.get(v);
			if(v == e.from && u == e.to) U.push_back(u);
		}
		int sz = len(U);
		assert((sz&1)==0);
		for(int i = 0; i < sz; i += 2) {
			cout << U[i] + 1 << ' ' << v + 1 << ' ' << U[i + 1] + 1 << '\n';
		}
	}
}

int main() {
	fast_io();
	solve();

	return 0;
}