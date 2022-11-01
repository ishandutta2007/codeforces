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
	#define DBG(X) dout << #X << "=" << (X) << '\n';
	#define SAY(X) dout << (X) << '\n';
#else
	#define DEBUG_OUTPUT_ENABLED 0
	#define DBG(X) 42;
	#define SAY(X) 42;
#endif

#define dout   debug::instance

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
				assert(DEBUG_OUTPUT_ENABLED);
				if(is_first) cout << "[DBG] ";
				cout << value;
				return DebugStream(false);
			};

			template<typename T> DebugStream printArray(T* l, T* r) {
				assert(DEBUG_OUTPUT_ENABLED);
				if(is_first) cout << "[DBG] ";
				while(l != r) {
					cout << (*l);
					++l;
					if(l == r) {
						cout << '\n';
					} else {
						cout << ' ';
					}
				}
				return DebugStream(false);
			}
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
const int MAXN = 507;
const int LOG  = 61;
bitset<MAXN> A[LOG][MAXN], B[LOG][MAXN];
bitset<MAXN> rA[LOG][MAXN], rB[LOG][MAXN];
int n, m;
ll dp[MAXN][LOG][2];
int used[MAXN][LOG][2];
void Dfsik(int v, int log, int i) {
	used[v][log][i] = 1;
	dp[v][log][i] = 0LL;
	if(i == 0) {
		if(log == 0) {
			for(int u = 0; u < n; ++u) {
				if(A[log][v][u]) {
					dp[v][log][i] = max(dp[v][log][i], 1LL << log);
				}
			}
		} else {
			for(int u = 0; u < n; ++u) {
				if(A[log][v][u]) {
					if(!used[u][log - 1][i^1]) Dfsik(u, log - 1, i^1);
					dp[v][log][i] = max(dp[v][log][i], (1LL << log) + dp[u][log - 1][i^1]);
				}
			}
		}
	} else {
		if(log == 0) {
			for(int u = 0; u < n; ++u) {
				if(B[log][v][u]) {
					dp[v][log][i] = max(dp[v][log][i], 1LL << log);
				}
			}
		} else {
			for(int u = 0; u < n; ++u) {
				if(B[log][v][u]) {
					if(!used[u][log - 1][i^1]) Dfsik(u, log - 1, i^1);
					dp[v][log][i] = max(dp[v][log][i], (1LL << log) + dp[u][log - 1][i^1]);
				}
			}
		}
	}
	if(log != 0) {
		if(!used[v][log - 1][i]) Dfsik(v, log - 1, i);
		dp[v][log][i] = max(dp[v][log][i], dp[v][log - 1][i]);
	}
}
void solve() {
	n = fetch<int>();
	m = fetch<int>();
	for(int i = 0; i < m; ++i) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		int t = fetch<int>();
		if(t == 0) A[0][v][u] = rA[0][u][v] = 1;
		if(t == 1) B[0][v][u] = rB[0][u][v] = 1;
	}
	for(int log = 1; log < LOG; ++log) {
		for(int v = 0; v < n; ++v) for(int u = 0; u < n; ++u) {
			A[log][v][u] = (A[log - 1][v] & rB[log - 1][u]).count() > 0;
			B[log][v][u] = (B[log - 1][v] & rA[log - 1][u]).count() > 0;
		}
		for(int v = 0; v < n; ++v) for(int u = 0; u < n; ++u) {
			rA[log][v][u] = A[log][u][v];
			rB[log][v][u] = B[log][u][v];
		}
	}
	/*for(int log = 0; log < 3; ++log) {
		for(int v = 0; v < n; ++v) for(int u = 0; u < n; ++u) {
			if(A[log][v][u]) dout << v + 1 << " -> " << u + 1 << "(" << log << ")\n";
		}
	}*/
	ll mx = 0;
	for(int v = 0; v < n; ++v) for(int log = 0; log < LOG; ++log) for(int i = 0; i < 2; ++i) {
		if(!used[v][log][i]) Dfsik(v, log, i);
		if(i == 0) mx = max(mx, dp[v][log][i]);
	}
	if(mx >= (ll)1e18) mx = NIL;
	cout << mx << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}