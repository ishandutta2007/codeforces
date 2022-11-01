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
const int MOD  = 998244353;
inline int add(int x, int y) {
	return (x + y >= MOD ? x + y - MOD : x + y);
}
inline int sub(int x, int y) {
	return (x - y < 0 ? x - y + MOD : x - y);
}
inline int mult(int x, int y) {
	ll r = x * 1LL * y;
	if(r >= MOD) r %= MOD;
	return (int)r;
}
int binpow(int x, int y) {
	if(x == 1 || y == 0) return 1;
	if(x == 0) return 0;
	int rez = binpow(x, y >> 1);
	rez = mult(rez, rez);
	if(y & 1) rez = mult(rez, x);
	return rez;
}
int divide(int x, int y) {
	return mult(x, binpow(y, MOD - 2));
}
const int MAXN = (int)1e6 + 7;
int n, F[MAXN], RF[MAXN], answ = 0;
void init() {
	F[0] = 1; for(int i = 1; i < MAXN; ++i) F[i] = mult(i, F[i - 1]);
	RF[MAXN - 1] = divide(1, F[MAXN - 1]); for(int i = MAXN - 2; i >= 0; --i) RF[i] = mult(i + 1, RF[i + 1]);
	assert(F[5] == 120%MOD);
	assert(mult(F[5], RF[5]) == 1%MOD);
}
int choose(int k, int n) {
	if(k > n) return 0;
	int rez = F[n];
	rez = mult(rez, RF[k]);
	rez = mult(rez, RF[n - k]);
	return rez;
}
inline void upd(int d) {
	answ = add(answ, d);
}
void kalk1() {
	int x = divide(1, 3);
	x = binpow(x, n);
	x = mult(x, sub(0, 3));
	int curPW = 1;
	for(int i = 0; i <= n; ++i) {
		int v = mult(curPW, choose(i, n));
		if(i) v = add(v, v);
		upd(v);
		curPW = mult(curPW, x);
	}
}
void slow_kalk2() {
	int x = divide(1, 3);
	x = binpow(x, n);
	x = sub(0, x);
	int y = 3;
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) {
		int cur = 3;
		cur = mult(cur, binpow(x, i));
		cur = mult(cur, binpow(x, j));
		cur = mult(cur, choose(i, n));
		cur = mult(cur, choose(j, n));
		cur = mult(cur, binpow(binpow(y, i), j));
		upd(cur);
	}
}
void kalk2() {
	int x = divide(1, 3);
	x = binpow(x, n);
	x = sub(0, x);
	int y = 3;
	int curPWX = x, curPWY = y;
	for(int i = 1; i <= n; ++i) {
		int value = mult(x, curPWY);
		value = add(value, 1);
		value = binpow(value, n);
		value = sub(value, 1);
		value = mult(value, curPWX);
		value = mult(value, choose(i, n));
		value = mult(value, 3);
		upd(value);
		curPWX = mult(curPWX, x);
		curPWY = mult(curPWY, y);
	}
}
void solve() {
	init();	n = fetch<int>();
	kalk1(); kalk2();
	int all = binpow(3, n);
	all = binpow(all, n);
	answ = sub(1, answ);
	answ = mult(answ, all);
	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}