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
const int MAXN = (int)1e6 + 7;
vector<pii> G[MAXN];
int n, tin[MAXN], last = 0;
int a[MAXN];
ll dp[MAXN];
void dfs(int v) {
	if(a[v]) tin[v] = last++;
	else tin[v] = INT_INF;
	for(auto& ed: G[v]) {
		int u = ed.second;
		dfs(u);
		tin[v] = min(tin[v], tin[u]);
	}
}
void calc(int v, ll mn, ll prevDP) {
	dp[v] = LL_INF;
	if(v == 0) dp[v] = min(dp[v], 0LL);
	dp[v] = min(dp[v], prevDP + 1);
	if(a[v]) dp[v] = min(dp[v], mn + tin[v]);
	mn = min(mn, dp[v] - tin[v] + 1);
	for(auto& ed: G[v]) {
		int u = ed.second;
		calc(u, mn, dp[v]);
	}
}
void solve() {
	cin >> n;
	++n;
	for(int i = 1; i < n; ++i) {
		int par = fetch<int>();
		int code = fetch<char>() - 'a';
		G[par].emplace_back(code, i);
	}
	int cnt = fetch<int>();
	auto X = fetch_vec<int>(cnt);
	for(auto& i: X) a[i] = 1;
	for(int i = 0; i < n; ++i) sort(G[i].begin(), G[i].end());
	dfs(0);
	calc(0, LL_INF, LL_INF);
	for(auto& i: X) cout << dp[i] << ' ';
	cout << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}