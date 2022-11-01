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

const int MAXN = (int)1e5 + 77;
int n, m, q;
vector<pii> byColor[MAXN], comps[MAXN];
vector<int> byVertex[MAXN];
int pa[MAXN], cnt[MAXN];
int hist[MAXN], head = 0;
void initDSU() {
	for(int v = 0; v < n; ++v) {
		pa[v] = v;
		cnt[v] = 1;
	}
}
int getParent(int v) {
	while(pa[v] != v) v = pa[v];
	return v;
}
int connect(int v, int u) {
	v = getParent(v);
	u = getParent(u);
	if(v == u) return 0;
	if(cnt[v] > cnt[u]) swap(v, u);
	pa[v] = u;
	cnt[u] += cnt[v];
	hist[head++] = v;
	return 1;
}
int undo() {
	if(head == 0) return 0;
	int v = hist[--head];
	cnt[pa[v]] -= cnt[v];
	pa[v] = v;
	return 1;
}
int getComp(int c, int v) {
	auto& a = comps[c];
	auto iter = lower_bound(a.begin(), a.end(), make_pair(v, NIL));
	if(iter == a.end() || iter->first != v) return NIL;
	return iter->second;
}
map<pii, int> mapchik;
void solve() {
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		int c = fetch<int>();
		byColor[c].emplace_back(v, u);
		byVertex[v].emplace_back(c);
		byVertex[u].emplace_back(c);
	}
	for(int v = 0; v < n; ++v) {
		auto& a = byVertex[v];
		sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()), a.end());
	}
	initDSU();
	for(int c = 0; c < MAXN; ++c) {
		while(undo());
		vector<int> V;
		for(auto& ed: byColor[c]) {
			connect(ed.first, ed.second);
			V.emplace_back(ed.first);
			V.emplace_back(ed.second);
		}
		sort(V.begin(), V.end());
		V.erase(unique(V.begin(), V.end()), V.end());
		for(auto& v: V) comps[c].emplace_back(v, getParent(v));
	}
	for(cin >> q; q > 0; --q) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		if(len(byVertex[v]) > len(byVertex[u])) swap(v, u);
		int answ = 0;
		auto Q = make_pair(v, u);
		if(mapchik.count(Q)) {
			answ = mapchik[Q];
		} else {
			for(auto& c: byVertex[v]) {
				answ += getComp(c, u) == getComp(c, v);
			}
			mapchik[Q] = answ;
		}
		cout << answ << '\n';
	}
}

int main() {
	fast_io();
	solve();

	return 0;
}