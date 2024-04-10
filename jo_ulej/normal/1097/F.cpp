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
const int MAXN = (int)1e5 + 7;
const int MAXC = 7000 + 123;
vector<int> D[MAXC], good;
int ok[MAXC], lp[MAXC];
bitset<MAXC> mask[MAXC];
void precalc() {
	for(int i = 1; i < MAXC; ++i) for(int j = i; j < MAXC; j += i) {
		D[j].emplace_back(i);
		if(lp[j] == 0 && i > 1) lp[j] = i;
	}
	ok[1] = 1;
	for(int i = 2; i < MAXC; ++i) {
		int p = lp[i];
		if((i/p)%p == 0) {
			ok[i] = 0;
		} else {
			ok[i] = ok[i/p];
		}
	}
	for(int i = 1; i < MAXC; ++i) if(ok[i]) {
		good.emplace_back(i);
	}
	DBG(len(good));
	for(int v = 1; v < MAXC; ++v) {
		for(auto& i: good) {
			int u = v * i;
			if(u >= MAXC) break;
			mask[v][u] = 1;
		}
	}
}
bitset<MAXC> A[MAXN], cached[MAXN];
map<int, int> mem[MAXN];
void solve() {
	precalc();	
	int n = fetch<int>();
	int q = fetch<int>();
	while(q--) {
		int cmd = fetch<int>();
		if(cmd == 1) {
			int x = fetch<int>();
			int v = fetch<int>();
			A[x].reset();
			cached[x].reset();
			for(auto& d: D[v]) A[x][d] = 1;
		} else if(cmd == 2) {
			int x = fetch<int>();
			int y = fetch<int>();
			int z = fetch<int>();
			A[x] = A[y] ^ A[z];
			cached[x].reset();
		} else if(cmd == 3) {
			int x = fetch<int>();
			int y = fetch<int>();
			int z = fetch<int>();
			A[x] = A[y] & A[z];
			cached[x].reset();
		} else if(cmd == 4) {
			int x = fetch<int>();
			int v = fetch<int>();
			if(cached[x][v]) {
				cout << mem[x][v];
				continue;
			}
			int rez = (A[x]&mask[v]).count()&1;
			cached[x][v] = 1;
			mem[x][v] = rez;
			cout << rez;
		} else {
			assert(false);
		}
	}
	cout << '\n';
}
int main() {
	fast_io();
	solve();

	return 0;
}