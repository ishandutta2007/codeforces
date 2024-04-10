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
int add(int x, int y) { return (x + y >= MOD ? x + y - MOD : x + y); }
int sub(int x, int y) { return (x - y < 0 ? x - y + MOD : x - y); }
int mult(int x, int y) { return (x * 1LL * y) % MOD; }
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
const int MAXN = (int)1e6 + 7;
int f[MAXN], revf[MAXN];
void init() {
	f[0] = 1;
	for(int i = 1; i < MAXN; ++i) f[i] = mult(i, f[i - 1]);
	revf[MAXN - 1] = divide(1, f[MAXN - 1]);
	for(int i = MAXN - 2; i >= 0; --i) revf[i] = mult(revf[i + 1], i + 1);
	assert(f[4] == 24%MOD);
	assert(mult(f[4], revf[4]) == 1%MOD);
}
int choose(int n, int k) {
	if(k > n) return 0;
	int rez = f[n];
	rez = mult(rez, revf[k]);
	rez = mult(rez, revf[n - k]);
	return rez;
}
int dp[MAXN], H[MAXN], pH[MAXN], n, k;
int getSum(int l, int r) {
	assert(l <= r);
	return sub(pH[r], pH[l - 1]);
}
void solve() {
	init();	
	cin >> n >> k;
	dp[1] = 1;
	for(int i = 2; i <= n; ++i) {
		H[i - 1] = mult(dp[i - 1], revf[i - 2]);
		pH[i - 1] = add(H[i - 1], pH[i - 2]);
		/*for(int j = 1; j <= min(k, i - 1); ++j) {
			int cur = dp[i - j];
			cur = mult(cur, f[i - 2]);
			cur = mult(cur, revf[i - j - 1]);
			dp[i] = add(dp[i], cur);
		}*/
		int mx = min(i - 1, k);
		int curSum = getSum(i - mx, i - 1);
		curSum = mult(curSum, f[i - 2]);
		dp[i] = curSum;
	}
	//(dout << "dp: ").printArray(&dp[1], &dp[n + 1]);
	int total = 0;
	for(int pos = 1; pos <= n; ++pos) {
		int cur = dp[pos];
		cur = mult(cur, choose(n - 1, pos - 1));
		cur = mult(cur, f[n - pos]);
		total = add(total, cur);
	}
	cout << sub(f[n], total) << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}