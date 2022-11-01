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

const int INT_INF = (int)(1e9);
const ll  LL_INF  = (ll)(2e18);

const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }
const int MAXN = 2007;
int masks[MAXN], n, k;
char dp[MAXN][MAXN];
int cost(int from, int to) {
	if((to & from) == from) {
		return __builtin_popcount(from ^ to);
	} else {
		return INT_INF;
	}
}
int D[] = {0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};
void solve() {
	cin >> n >> k;
	for(int i = 0; i < n; ++i) {
		auto S = fetch<string>();
		reverse(S.begin(), S.end());
		for(int j = 0; j < len(S); ++j) if(S[j] == '1') masks[i] |= (1 << j);
	}
	for(int i = 0, j = n - 1; i < j; ++i, --j) swap(masks[i], masks[j]);
	dp[0][0] = 1;
	for(int i = 0; i < n; ++i) for(int j = 0; j <= k; ++j) {
		if(!dp[i][j]) continue;
		for(int p = 0; p < 10; ++p) {
			int j2 = j + cost(masks[i], D[p]);
			if(j2 <= k) dp[i + 1][j2] = 1;
		}
	}
	//for(int i = 0; i <= n; ++i) for(int j = 0; j <= k; ++j) dout << i << ',' << j << ": " << (int)dp[i][j] << '\n';
	if(dp[n][k]) {
		string rez;
		int i = n, j = k;
		while(i) {
			int found = 0;
			for(int p = 9; p >= 0; --p) {
				int i2 = i - 1, j2 = j - cost(masks[i - 1], D[p]);
				if(j2 >= 0 && j2 <= k && dp[i2][j2]) {
					i = i2, j = j2;
					rez.push_back('0' + p);
					found = 1;
					break;
				}
			}
			assert(found);
		}
		//reverse(rez.begin(), rez.end());
		cout << rez << '\n';
	} else {
		cout << "-1\n";
	}
}

int main() {
	fast_io();
	solve();

	return 0;
}