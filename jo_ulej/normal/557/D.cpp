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
	#define DEBUG_OUTPUD_ENABLED 1
#else
	#define DEBUG_OUTPUD_ENABLED 0
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
				if(DEBUG_OUTPUD_ENABLED) {
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
vector<int> G[MAXN];
int n, m;
int used[MAXN], color[MAXN];
int cnt[MAXN][2], good = 1;
int last = 0;
void dfs(int v, int col) {
	used[v] = 1;
	color[v] = col;
	++cnt[last][col];
	for(auto& u: G[v]) {
		if(!used[u]) dfs(u, col^1);
		if(color[u] == color[v]) good = 0;
	}
}
ll pairs(ll x) {
	if(x < 2) return 0;
	return (x * (x - 1)) / 2;
}
void solve() {
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		G[v].emplace_back(u);
		G[u].emplace_back(v);
	}
	for(int v = 0; v < n; ++v) if(!used[v]) {
		dfs(v, 0);
		++last;
	}
	if(!good) {
		cout << "0 1\n";
		return;
	}
	int found = 0;
	for(int i = 0; i < last; ++i) {
		if(cnt[i][0] > 1 || cnt[i][1] > 1) {
			found = 1;
			break;
		}
	}
	if(found) {
		ll ways = 0;
		for(int i = 0; i < last; ++i) {
			ways += pairs(cnt[i][0]);
			ways += pairs(cnt[i][1]);
		}
		cout << "1 " << ways << '\n';
		return;
	}
	ll small = 0, big = 0;
	for(int i = 0; i < last; ++i) {
		int sz = cnt[i][0] + cnt[i][1];
		if(sz == 1) ++small;
		if(sz == 2) ++big;
		assert(sz >= 1 && sz <= 2);
	}
	dout << "S,B=" << small << ' ' << big << '\n';
	if(big > 0) {
		cout << "2 " << big * (n - 2) << '\n';
		return;
	}
	if(small > 0) {
		ll answ = 1;
		answ *= small;
		answ *= small - 1;
		answ *= small - 2;
		answ /= 6;
		cout << "3 " << answ << '\n';
		return;
	}
	assert(false);
}
int main() {
	fast_io();
	solve();

	return 0;
}