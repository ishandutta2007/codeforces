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
const int MAXN = 407;
bitset<MAXN> dp[MAXN][MAXN]; // dp[k][i][j]
string S, T;
int check(const string& left, const string& right, const string& str) {
	for(int k = 0; k <= len(str); ++k) for(int i = 0; i <= len(left); ++i) dp[k][i].reset();
	dp[0][0][0] = 1;
	bitset<MAXN> cur;
	for(int k = 1; k <= len(str); ++k) {
		for(int j = 0; j < len(right); ++j) {
			cur[j] = (str[k - 1] == right[j]);
		}
		for(int i = 0; i <= len(left); ++i) {
			dp[k][i] |= dp[k - 1][i];
			if(i > 0 && str[k - 1] == left[i - 1]) {
				dp[k][i] |= dp[k - 1][i - 1];
			}
			/*for(int j = 0; j <= len(right); ++j) {
				if(j > 0 && str[k - 1] == right[j - 1]) {
					dp[k][i][j] = dp[k][i][j] | dp[k - 1][i][j - 1];
				}
			}*/
			dp[k][i] |= (dp[k - 1][i]&cur)<<1;
		}
	}
	/*for(int k = 0; k <= len(str); ++k) for(int i = 0; i <= len(left); ++i) for(int j = 0; j <= len(right); ++j) {
		dout << k << ' ' << i << ' ' << j << ' ' << dp[k][i][j] << '\n';
	}*/
	return dp[len(str)][len(left)][len(right)];
}
void solve() {
	cin >> S >> T;
	for(int i = 0; i <= len(T); ++i) {
		string pref, suff;
		for(int pos = 0; pos < len(T); ++pos) {
			if(pos < i) {
				pref.push_back(T[pos]);
			} else {
				suff.push_back(T[pos]);
			}
		}
		int rez = check(pref, suff, S);
		//DBG(pref); DBG(suff); DBG(rez);
		if(rez) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main() {
	fast_io();
	int T = fetch<int>();
	while(T--) {
		solve();
	}

	return 0;
}