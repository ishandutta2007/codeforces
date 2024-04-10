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
const int MAXN = (int)2e5 + 77;
const int LOG  = 20;
vector<int> G[MAXN];
int p[MAXN], q[MAXN], n;
int depth[MAXN];
int ord[2 * MAXN], pos[MAXN], head;
int SPT[LOG][2 * MAXN], lg[2 * MAXN];
inline int choose(int v, int u) {
	return (depth[v] < depth[u] ? v : u);
}
void dfsInit(int v) {
	ord[head++] = v;
	pos[v] = head - 1;
	for(auto& u: G[v]) {
		depth[u] = depth[v] + 1;
		dfsInit(u);
		ord[head++] = v;
	}
}
inline int getLCA(int v, int u) {
	int l = pos[v], r = pos[u];
	if(l > r) swap(l, r);
	int log = lg[r - l + 1];
	return choose(SPT[log][l], SPT[log][r - (1 << log) + 1]);
}
inline int getDist(int v, int u) {
	int w = getLCA(v, u);
	return depth[v] + depth[u] - 2 * depth[w];
}
inline int between(int a, int b, int c) {
	return getDist(a, b) + getDist(b, c) == getDist(a, c);
}
inline pii combine(const pii& lhs, const pii& rhs) {
	if(lhs.first == NIL) return lhs;
	if(rhs.first == NIL) return rhs;
	int a = lhs.first, b = lhs.second, c = rhs.first, d = rhs.second;
	if(between(a, c, b) && between(a, d, b)) return {a, b};
	if(between(a, b, c) && between(a, d, c)) return {a, c};
	if(between(a, b, d) && between(a, c, d)) return {a, d};
	if(between(b, a, c) && between(b, d, c)) return {b, c};
	if(between(b, a, d) && between(b, c, d)) return {b, d};
	if(between(c, a, d) && between(c, b, d)) return {c, d};
	return {NIL, NIL};
}
pii tree[2 * MAXN];
inline void build() {
	for(int i = 0; i < n; ++i) tree[i + n] = make_pair(q[i], q[i]);
	for(int i = n - 1; i > 0; --i) tree[i] = combine(tree[2 * i], tree[2 * i + 1]);
}
inline void upd(int pos) {
	tree[n + pos] = make_pair(q[pos], q[pos]);
	for(pos += n; pos > 1; pos >>= 1) tree[pos >> 1] = combine(tree[pos], tree[pos ^ 1]);
}
inline pii get(int l, int r) {
	l += n, r += n + 1;
	pii rez = tree[l];
	while(l < r) {
		if(l & 1) rez = combine(rez, tree[l++]);
		if(r & 1) rez = combine(rez, tree[--r]);
		l >>= 1, r >>= 1;
	}
	return rez;
}
int check(int pref) {
	if(pref <= 1) return 1;
	return get(0, pref - 1).first != NIL;
}
void solve() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> p[i];
		q[p[i]] = i;
	}
	for(int v = 1; v < n; ++v) {
		int u = fetch<int>() - 1;
		G[u].emplace_back(v);
	}
	depth[0] = 0;
	head = 0;
	dfsInit(0);
	for(int i = 2; i < 2 * MAXN; ++i) lg[i] = 1 + lg[i >> 1];
	for(int i = 0; i < head; ++i) SPT[0][i] = ord[i];
	for(int log = 1; log < LOG; ++log) {
		int sz = 1 << log;
		for(int i = 0; i + sz - 1 < head; ++i) {
			SPT[log][i] = choose(SPT[log - 1][i], SPT[log - 1][i + sz / 2]);
		}
	}
	int cntQueries = fetch<int>();
	build();
	for(int que = 0; que < cntQueries; ++que) {
		int type = fetch<int>();
		if(type == 1) {
			int v = fetch<int>() - 1;
			int u = fetch<int>() - 1;
			swap(q[p[v]], q[p[u]]);
			swap(p[v], p[u]);
			upd(p[v]);
			upd(p[u]);
		} else if(type == 2) {
			int low = 0, high = n + 1;
			while(high - low > 1) {
				int mid = (low + high) / 2;
				if(check(mid)) {
					low = mid;
				} else {
					high = mid;
				}
			}
			cout << low << '\n';
		} else {
			assert(false);
		}
	}
}

int main() {
	fast_io();
	solve();

	return 0;
}