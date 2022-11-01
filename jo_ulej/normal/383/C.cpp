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

			template<typename T> DebugStream printArray(T* l, T* r) {
				if(DEBUG_OUTPUT_ENABLED) {
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
struct Fenwick {
	ll* F = nullptr;
	int sz;
	Fenwick(int _sz): sz(_sz) {
		F = new ll[sz];
		memset(F, 0, sizeof(F[0]) * sz);
	}
	void add(int pos, ll val) {
		for(; pos < sz; pos |= pos + 1) F[pos] += val;
	}
	ll get(int r) {
		ll rez = 0;
		for(; r >= 0; r = (r & (r + 1)) - 1) rez += F[r];
		return rez;
	}
};
const int MAXN = 200000 + 7;
vector<int> G[MAXN];
int n, q, root = 0;
int ord[MAXN], L[MAXN], R[MAXN], ordSz = 0;
int depth[MAXN];
Fenwick oddFenv(MAXN), evenFenv(MAXN);
ll a[MAXN];
void dfsik(int v, int prv) {
	depth[v] = (prv == NIL ? 0 : depth[prv] + 1);
	ord[ordSz++] = v;
	L[v] = ordSz - 1;
	for(auto& u: G[v]) if(u != prv) {
		dfsik(u, v);
	}
	R[v] = ordSz - 1;
}
void solve() {
	cin >> n >> q;
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n - 1; ++i) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		G[v].emplace_back(u);
		G[u].emplace_back(v);
	}
	dfsik(root, NIL);
	while(q--) {
		int cmd = fetch<int>();
		if(cmd == 1) {
			int v = fetch<int>() - 1;
			ll val = fetch<ll>();
			if(depth[v]&1) val = -val;
			evenFenv.add(L[v], val);
			evenFenv.add(R[v] + 1, -val);
			oddFenv.add(L[v], -val);
			oddFenv.add(R[v] + 1, val);
		} else if(cmd == 2) {
			int v = fetch<int>() - 1;
			ll answ = a[v];
			if(depth[v]&1) {
				answ += oddFenv.get(L[v]);
			} else {
				answ += evenFenv.get(L[v]);
			}
			cout << answ << '\n';
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