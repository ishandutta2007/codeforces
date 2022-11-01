#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,mmx,sse,sse2")

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
const int MOD = (int)1e9 + 7;
int add(int x, int y) {
	return (x + y >= MOD ? x + y - MOD : x + y);
}
int mult(int x, int y) {
	return (x * 1LL * y) % MOD;
}
const int MAXN = 5007;
int s[MAXN], f[MAXN], h[MAXN];
int n, m;
int x[MAXN], y[MAXN];
int mustLeft[MAXN], canLeft[MAXN], canRight[MAXN], canBoth[MAXN];
inline int choose(int n, int k) {
	if(k > n) return 0;
	int rez = 1;
	for(int i = 0; i < k; ++i) rez *= n - i;
	return rez;
}
void solve() {
	n = fetch<int>();
	m = fetch<int>();
	for(int i = 0; i < n; ++i) s[i] = fetch<int>();
	for(int i = 0; i < m; ++i) {
		f[i] = fetch<int>();
		h[i] = fetch<int>();
	}
	for(int i = 0; i < m; ++i) {
		int minPref = 0, minSuff = 0;
		int cnt = 0;
		while(minPref < n && cnt != h[i]) cnt += (s[minPref++] == f[i]);
		if(cnt != h[i]) minPref = n + 1;
		cnt = 0;
		while(minSuff < n && cnt != h[i]) cnt += (s[n - (++minSuff)] == f[i]);
		if(cnt != h[i]) minSuff = n + 1;
		x[i] = minPref;
		y[i] = minSuff;
#ifdef __LOCAL
		dout << i + 1 << ": " << minPref << ' ' << minSuff << '\n';
#endif
	}
	int mxRez = NIL;
	int ways = NIL;
	for(int i = NIL; i < m; ++i) {
		int a = i == NIL ? NIL : x[i];
		int b = i == NIL ? n : n - a;
		if(a > n) continue;
		memset(mustLeft, 0, sizeof(mustLeft));
		memset(canLeft, 0, sizeof(canLeft));
		memset(canRight, 0, sizeof(canRight));
		memset(canBoth, 0, sizeof(canBoth));
		int fnd = i == NIL ? 1 : 0;
		for(int j = 0; j < m; ++j) {
			if(x[j] == a) {
				fnd = 1;
				//++canLeft[f[j]];
				++mustLeft[f[j]];
			} else {
				if(x[j] <= a && y[j] <= b) {
					++canBoth[f[j]];
				} else if(x[j] <= a) {
					++canLeft[f[j]];
				} else if(y[j] <= b) {
					++canRight[f[j]];
				}
			}
		}
		if(fnd == 0) continue;
		int cnt = 0, w = 1;
		for(int co = 0; co < MAXN; ++co) {
			if(canBoth[co] || canLeft[co] || mustLeft[co] || canRight[co]) {
				DBG(canBoth[co]);
				DBG(canLeft[co]);
				DBG(mustLeft[co]);
				DBG(canRight[co]);
			} else {
				continue;
			}
			int toAdd = min(canLeft[co] + mustLeft[co], 1) + min(canRight[co], 1);
			int delta = toAdd + min(2 - toAdd, canBoth[co]);
			cnt += delta;
			DBG(delta);
			if(delta == 0) continue;
			if(mustLeft[co] == 1) {
				if(delta == 2) {
					int mlt = canRight[co] + canBoth[co];
					w = mult(mlt, w);
					DBG(mlt);
				}
			} else {
				if(delta == 1) {
					if(canLeft[co] != 0) {
						w = mult(w, canLeft[co]);
					}
					if(canRight[co] != 0) {
						w = mult(w, canRight[co]);
					}
					if(canBoth[co] != 0) {
						w = mult(w, canBoth[co]);
						w = add(w, w);
					}
				} else {
					int mlt = 0;
					mlt = add(mlt, mult(canLeft[co], canRight[co]));
					mlt = add(mlt, mult(canLeft[co], canBoth[co]));
					mlt = add(mlt, mult(canBoth[co], canRight[co]));
					mlt = add(mlt, choose(canBoth[co], 2));
					DBG(mlt);
					w = mult(w, mlt);
				}
			}
		}
		DBG(cnt);
		DBG(w);
		if(cnt > mxRez) {
			mxRez = cnt;
			ways = w;
		} else if(cnt == mxRez) {
			ways = add(ways, w);
		}
		//SAY("END");
	}
	// We should also could the case when first set is empty
	if(mxRez == 0) ways = 1;
	cout << mxRez << ' ' << ways << '\n';
}

signed main() {
	fast_io();
	solve();

	return 0;
}