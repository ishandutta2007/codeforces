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

#define dout   ___debug::instance

using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const set<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const map<T, S>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const multiset<T>& v) { for(auto el: v) cout << el << " "; return os; }
namespace ___debug {
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

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }
const int MAXN = 1007;
const int LOG  = 20;
vector<int> G[MAXN];
int n;
int depth[MAXN], BL[LOG][MAXN];
int tin[MAXN], tout[MAXN], timer;
void dfsInit(int v, int prv) {
	tin[v] = timer++;
	depth[v] = (prv == NIL ? 0 : depth[prv] + 1);
	BL[0][v] = (prv == NIL ? v : prv);
	for(auto& u: G[v]) if(u != prv) {
		dfsInit(u, v);
	}
	tout[v] = timer++;
}
int isParent(int v, int u) {
	return (tin[v] <= tin[u] && tout[u] <= tout[v]);
}
int getLCA(int v, int u) {
	if(depth[v] < depth[u]) swap(v, u);
	int h = depth[v] - depth[u];
	for(int i = 0; i < LOG; ++i) if((h >> i) & 1) v = BL[i][v];
	if(v == u) return v;
	for(int i = LOG - 1; i >= 0; --i) {
		if(BL[i][v] != BL[i][u]) {
			v = BL[i][v];
			u = BL[i][u];
		}
	}
	return BL[0][v];
}
int askMeToYou(int v) {
	cout << "A " << v + 1 << '\n';
	flush(cout);
	return fetch<int>() - 1;
}
int askYouToMe(int v) {
	cout << "B " << v + 1 << '\n';
	flush(cout);
	return fetch<int>() - 1;
}
void submitAnsw(int v) {
	cout << "C " << (v == NIL ? NIL : v + 1) << '\n';
	flush(cout);
}
void solve() {
	cin >> n;
	for(int v = 0; v < n; ++v) G[v].clear();
	for(int id = 0; id < n - 1; ++id) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		G[v].emplace_back(u);
		G[u].emplace_back(v);
	}
	int meSz = fetch<int>();
	auto me = fetch_vec<int>(meSz);
	int youSz = fetch<int>();
	auto you = fetch_vec<int>(youSz);
	for(auto& v: me) --v;
	for(auto& v: you) --v;
	timer = 0;
	dfsInit(0, NIL);
	for(int log = 1; log < LOG; ++log) for(int v = 0; v < n; ++v) BL[log][v] = BL[log - 1][BL[log - 1][v]];
	int rt = me[0];
	for(auto& v: me) rt = getLCA(rt, v);
	int rtInYou = askMeToYou(rt);
	int foundRtInYou = 0;
	for(auto& v: you) if(v == rtInYou) {
		foundRtInYou = 1;
		break;
	}
	if(foundRtInYou) {
		submitAnsw(rt);
		return;
	}
	int someone = askYouToMe(you[0]);
	int vert = NIL;
	for(auto& v: me) {
		if(isParent(v, someone)) {
			if(vert == NIL || depth[v] > depth[vert]) vert = v;
		}
	}
	if(vert == NIL) {
		submitAnsw(vert);
		return;
	}
	int foundVertInYou = 0;
	int vertInYou = askMeToYou(vert);
	for(auto& v: you) if(v == vertInYou) {
		foundVertInYou = 1;
		break;
	}
	if(!foundVertInYou) {
		vert = NIL;
	}
	submitAnsw(vert);
}

int main() {
	//fast_io();
	int T = fetch<int>();
	while(T--) solve();

	return 0;
}