#pragma GCC optimize("Ofast")
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
int GCD(int x, int y) {
	return x ? GCD(y % x, x) : y;
}
const int MAXN = (int)2e5 + 77;
int a[2 * MAXN], b[2 * MAXN], n;
int pref[MAXN], mx[MAXN], gcdWithN[MAXN];
void solve() {
	cin >> n;
	for(int i = 0; i <= n; ++i) gcdWithN[i] = GCD(i, n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = n; i < 2 * n; ++i) a[i] = a[i - n];
	ll answ = 0;
	for(int g = 1; g < n; ++g) if(n % g == 0) {
		DBG(g);
		pref[0] = 0;
		for(int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + (gcdWithN[i] == g);
		//(dout << "@pref: ").printArray(pref, pref + n + 1);
		for(int i = 0; i < g; ++i) mx[i] = 0;
		int ptr = 0;
		for(int i = 0; i < n; ++i) {
			mx[ptr] = max(mx[ptr], a[i]);
			++ptr;
			if(ptr >= g) ptr -= g;
		}
		ptr = 0;
		for(int i = 0; i < 2 * n; ++i) {
			b[i] = mx[ptr];
			++ptr;
			if(ptr >= g) ptr -= g;
		}
		//(dout << "@b: ").printArray(b, b + 2 * n);
		int sz = 0;
		for(int i = 0; i < n; ++i) {
			while(sz < n && b[i + sz] <= a[i + sz]) ++sz;
			//dout << i << ": " << sz << '(' << pref[sz] << ")\n";
			if(sz) {
				answ += pref[sz];
				--sz;
			}
		}
	}
	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}