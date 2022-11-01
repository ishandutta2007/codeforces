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
const int MAXN = (int)3e5 + 7;
const int A    = 26;
vector<int> G[MAXN];
int c[MAXN];
int n, m;
int good = 1;
int used[MAXN], dp[MAXN], p;
void dfsCheck(int v) {
	used[v] = 1;
	for(auto& u: G[v]) {
		if(used[u]) {
			if(used[u] == 1) good = 0;
		} else {
			dfsCheck(u);
		}
	}
	used[v] = 2;
}
void dfsCalc(int v) {
	used[v] = 1;
	dp[v] = 0;
	for(auto& u: G[v]) {
		if(!used[u]) dfsCalc(u);
		dp[v] = max(dp[v], dp[u]);
	}
	dp[v] += (c[v] == p);
}
void solve() {
	n = fetch<int>();
	m = fetch<int>();
	auto S = fetch<string>();
	for(int v = 0; v < n; ++v) c[v] = S[v] - 'a';
	for(int i = 0; i < m; ++i) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		G[v].emplace_back(u);
	}
	for(int v = 0; v < n; ++v) if(!used[v]) dfsCheck(v);
	if(!good) {
		cout << "-1\n";
		return;
	}
	int answ = 0;
	for(p = 0; p < A; ++p) {
		memset(used, 0, sizeof(used));
		memset(dp, 0, sizeof(dp));
		for(int v = 0; v < n; ++v) {
			if(!used[v]) dfsCalc(v);
			answ = max(answ, dp[v]);
		}
	}
	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}