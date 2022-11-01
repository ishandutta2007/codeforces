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
const int MAXN = (int)2e5 + 7;
vector<int> G[MAXN];
ll a[MAXN], dp[MAXN][2];
int n, rootik;
vector<int> go[2 * MAXN];
int val[2 * MAXN];
int can[MAXN][2], head = 0;
inline int Alloc() {
	val[head] = NIL;
	return head++;
}
inline void Insert(int v, int x) {
	assert(val[v] == NIL);
	val[v] = x;
}
inline void Connect(int v, int child) {
	go[v].emplace_back(child);
}
void Dfs(int v, int prv) {
	can[v][0] = Alloc();
	can[v][1] = Alloc();
	dp[v][0] = dp[v][1] = 0LL;
	int leaf = 1;
	for(auto& u: G[v]) if(u != prv) leaf = 0;
	if(leaf) {
		dp[v][0] = a[v];
		Insert(can[v][0], v);
		dp[v][1] = 0;
		return;
	}
	ll mn0 = 0, mn1 = 0;
	int cnt0 = 0, cnt1 = 0;
	for(auto& u: G[v]) if(u != prv) {
		Dfs(u, v);
		dp[v][0] += dp[u][0];
		ll loc0 = dp[u][1] - dp[u][0] + a[v];
		if(loc0 < mn0) {
			mn0 = loc0;
			cnt0 = 1;
		} else if(loc0 == mn0) {
			++cnt0;
		}
		dp[v][1] += dp[u][0];
		ll loc1 = dp[u][1] - dp[u][0];
		if(loc1 < mn1) {
			mn1 = loc1;
			cnt1 = 1;
		} else if(loc1 == mn1) {
			++cnt1;
		}
	}
	dp[v][0] += mn0;
	dp[v][1] += mn1;
	/*dout << v + 1 << " (dp01): " << dp[v][0] << ' ' << dp[v][1] << '\n';
	dout << v + 1 << " (mn01): " << mn0 << ' ' << mn1 << '\n';
	dout << v + 1 << " (cn01): " << cnt0 << ' ' << cnt1 << '\n';*/
	if(cnt0 == 0) {
		for(auto& u: G[v]) if(u != prv) {
			//can[v][0] = Merge(can[v][0], can[u][0]);
			Connect(can[v][0], can[u][0]);
		}
	} else if(cnt0 == 1 && mn0 < 0) {
		Insert(can[v][0], v);
		for(auto& u: G[v]) if(u != prv) {
			if(dp[u][1] - dp[u][0] + a[v] == mn0) {
				//can[v][0] = Merge(can[v][0], can[u][1]);
				Connect(can[v][0], can[u][1]);
			} else {
				//can[v][0] = Merge(can[v][0], can[u][0]);
				Connect(can[v][0], can[u][0]);
			}
		}
	} else {
		Insert(can[v][0], v);
		for(auto& u: G[v]) if(u != prv) {
			if(dp[u][1] - dp[u][0] + a[v] == mn0) {
				//can[v][0] = Merge(can[v][0], can[u][1]);
				Connect(can[v][0], can[u][1]);
			}
			//can[v][0] = Merge(can[v][0], can[u][0]);
			Connect(can[v][0], can[u][0]);
		}
	}
	if(cnt1 == 0) {
		for(auto& u: G[v]) if(u != prv) {
			//can[v][1] = Merge(can[v][1], cloneCan[u][0]);
			Connect(can[v][1], can[u][0]);
		}
	} else if(cnt1 == 1 && mn1 < 0) {
		for(auto& u: G[v]) if(u != prv) {
			if(dp[u][1] - dp[u][0] == mn1) {
				//can[v][1] = Merge(can[v][1], cloneCan[u][1]);
				Connect(can[v][1], can[u][1]);
			} else {
				//can[v][1] = Merge(can[v][1], cloneCan[u][0]);
				Connect(can[v][1], can[u][0]);
			}
		}
	} else {
		for(auto& u: G[v]) if(u != prv) {
			if(dp[u][1] - dp[u][0] == mn1) {
				//can[v][1] = Merge(can[v][1], cloneCan[u][1]);
				Connect(can[v][1], can[u][1]);
			}
			//can[v][1] = Merge(can[v][1], cloneCan[u][0]);
			Connect(can[v][1], can[u][0]);
		}
	}
	/*dout << v + 1 << ", can0: " << asVector(can[v][0], 1) << '\n';
	dout << v + 1 << ", can1: " << asVector(can[v][1], 1) << '\n';*/
	//assert(dp[v][1] <= dp[v][0]);
}
int Q[MAXN], last = 0;
int used[2 * MAXN];
void extract(int v) {
	used[v] = 1;
	if(val[v] != NIL) Q[last++] = val[v];
	for(auto& u: go[v]) if(!used[u]) extract(u);
}
void solve() {
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n - 1; ++i) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		G[v].emplace_back(u);
		G[u].emplace_back(v);
	}
	rootik = 0;
	Dfs(rootik, NIL);
	/*for(int v = 0; v < n; ++v) {
		dout << v + 1 << ": " << dp[v][0] << ' ' << dp[v][1] << '\n';
	}*/
	ll answS = dp[rootik][0];
	extract(can[rootik][0]);
	cout << answS << ' ' << last << '\n';
	sort(Q, Q + last);
	for(int i = 0; i < last; ++i) cout << Q[i] + 1 << ' ';
	cout << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}