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
const int MAXN = (int)3e5 + 777;
int a[MAXN], n, k;
vector<int> which[MAXN];
vector<int> comp[MAXN];
int pa[MAXN], answ = 0;
int must[MAXN], color[MAXN], cnt[MAXN][2];
void initDSU() {
	for(int i = 0; i < k; ++i) {
		pa[i] = i;
		comp[i].push_back(i);
		must[i] = NIL;
		color[i] = 0;
		cnt[i][0] = 1;
		cnt[i][1] = 0;
	}
}
int getParent(int v) {
	while(pa[v] != v) v = pa[v];
	return v;
}
int calc(int v) {
	assert(pa[v] == v);
	if(must[v] == NIL) return min(cnt[v][0], cnt[v][1]);
	return cnt[v][must[v]];
}
void connect(int v, int u, int x) {
	int pv = getParent(v);
	int pu = getParent(u);
	DBG(v); DBG(u); DBG(pv); DBG(pu);
	if(pv == pu) return;
	if(len(comp[pv]) > len(comp[pu])) {
		swap(v, u);
		swap(pv, pu);
	}
	if((color[v] ^ color[u]) != x) {
		for(auto& el: comp[pv]) {
			color[el] ^= 1;
		}
		if(must[pv] != NIL) must[pv] ^= 1;
		swap(cnt[pv][0], cnt[pv][1]);
	}
	//if(must[pu] != NIL) answ -= cnt[pu][must[pu]];
	//if(must[pv] != NIL) answ -= cnt[pv][must[pv]];
	answ -= calc(pv);
	answ -= calc(pu);
	for(auto& el: comp[pv]) {
		comp[pu].push_back(el);
		pa[el] = pu;
		++cnt[pu][color[el]];
	}
	if(must[pv] != NIL) must[pu] = must[pv];
	//if(must[pu] != NIL) answ += cnt[pu][must[pu]];
	answ += calc(pu);
}
void solve() {
	cin >> n >> k;
	auto S = fetch<string>();
	for(int i = 0; i < n; ++i) a[i] = S[i] - '0';
	for(int i = 0; i < k; ++i) {
		int cnt = fetch<int>();
		for(int j = 0; j < cnt; ++j) {
			int pos = fetch<int>() - 1;
			which[pos].push_back(i);
		}
	}
	initDSU();
	for(int i = 0; i < n; ++i) {
		if(which[i].empty()) {
			assert(a[i] == 1);
		} else if(len(which[i]) == 1) {
			int id = which[i].front();
			int v = getParent(id);
			if(must[v] == NIL) {
				answ -= calc(v);
				must[v] = color[id] ^ a[i];
				//answ += cnt[v][must[v]];
				answ += calc(v);
			} else {
				assert(must[v] == (color[id] ^ a[i]));
			}
		} else {
			assert(len(which[i]) == 2);
			connect(which[i].front(), which[i].back(), a[i] ^ 1);
		}
		cout << answ << '\n';
	}
}

int main() {
	fast_io();
	solve();

	return 0;
}