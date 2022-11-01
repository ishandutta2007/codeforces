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
const int MOD = (int)1e9 + 7;
int add(int x, int y) {
	return (x + y >= MOD ? x + y - MOD : x + y);
}
int mult(int x, int y) {
	return (x * 1LL * y) % MOD;
}
void radd(int& x, int y) {
	x = add(x, y);
}
const int MAXN = 2007;
int a[MAXN], n, h;
int dp[MAXN][MAXN];
void solve() {
	cin >> n >> h;
	for(int i = 0; i < n; ++i) cin >> a[i];
	dp[0][0] = 1;
	for(int pos = 0; pos < n; ++pos) for(int bal = 0; bal <= n; ++bal) {
		int v = dp[pos][bal]; if(v == 0) continue;
		for(int open = 0; open < 2; ++open) {
			for(int close = 0; close < 2; ++close) {
				if(close && bal == 0) continue;
				int bal2 = bal + open - close;
				if(bal2 < 0 || a[pos] + bal2 != h) continue;
				radd(dp[pos + 1][bal2], close ? mult(v, bal) : v);
			}
		}
	}
	for(int pos = 0; pos <= n; ++pos) for(int bal = 0; bal <= n; ++bal) {
		dout << pos << ' ' << bal << ' ' << dp[pos][bal] << '\n';
	}
	cout << add(dp[n][0], dp[n][1]) << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}