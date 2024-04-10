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
const int MAXN = (int)3e5 + 7;
int add(int x, int y) {
	return (x + y >= MOD ? x + y - MOD : x + y);
}
int mult(int x, int y) {
	ll rez = x * 1LL * y;
	if(rez >= MOD) rez %= MOD;
	return (int)rez;
}
int binpow(int x, int y) {
	if(x == 1 || y == 0) return 1;
	if(x == 0) return 0;
	int rez = binpow(x, y>>1);
	rez = mult(rez, rez);
	if(y&1) rez = mult(rez, x);
	return rez;
}
int divide(int x, int y) {
	return mult(x, binpow(y, MOD - 2));
}
int Fact[MAXN], RevFact[MAXN], pw2[MAXN];
void initF() {
	Fact[0] = 1;
	for(int i = 1; i < MAXN; ++i) Fact[i] = mult(i, Fact[i - 1]);
	RevFact[MAXN - 1] = divide(1, Fact[MAXN - 1]);
	for(int i = MAXN - 2; i >= 0; --i) RevFact[i] = mult(i + 1, RevFact[i + 1]);
	pw2[0] = 1;
	for(int i = 1; i < MAXN; ++i) pw2[i] = add(pw2[i - 1], pw2[i - 1]);
	assert(Fact[5] == 120%MOD);
	assert(mult(Fact[123], RevFact[123]) == 1);
	assert(pw2[4] == 16%MOD);
}
int C(int k, int n) {
	assert(k >= 0 && n >= 0);
	if(k > n) return 0;
	int rez = Fact[n];
	rez = mult(rez, RevFact[k]);
	rez = mult(rez, RevFact[n - k]);
	return rez;
}
void solve() {
	initF();
	int n = fetch<int>();
	int m = fetch<int>();
	if(n <= 2) {
		cout << "0\n";
		return;
	}
	int answ = C(n - 1, m);
	answ = mult(answ, n - 2);
	answ = mult(answ, pw2[n - 3]);
	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}