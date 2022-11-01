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
const int MAXN = (int)1e5 + 77;
const int MAXP = 8;
const int SZ   = 130;
int n, p, k;
struct Data {
	ll a, b[MAXP];
	bool operator<(const Data& other) const {
		return a < other.a;
	}
};
Data Z[MAXN];
ll dp[MAXP][SZ], dp2[MAXP][SZ];
void relax(ll& x, ll y) {
	x = (y > x ? y : x);
}
vector<int> unsetBits[SZ];
void solve() {
	cin >> n >> p >> k;
	for(int msk = 0; msk < (1 << p); ++msk) for(int j = 0; j < p; ++j) {
		if(((msk>>j)&1) == 0) unsetBits[msk].emplace_back(j);
	}
	for(int i = 0; i < n; ++i) cin >> Z[i].a;
	for(int i = 0; i < n; ++i) for(int j = 0; j < p; ++j) cin >> Z[i].b[j];
	sort(Z, Z + n);
	reverse(Z, Z + n);
	for(int i = 0; i < MAXP; ++i) for(int j = 0; j < SZ; ++j) dp[i][j] = dp2[i][j] = -LL_INF;
	dp[0][0] = 0;
	for(int pos = 0; pos < n; ++pos) {
		for(int i = 0; i <= p; ++i) for(int j = 0; j < (1 << p); ++j) dp2[i][j] = -LL_INF;
		for(int bal = 0; bal <= p; ++bal) for(int msk = 0; msk < (1 << p); ++msk) {
			if(dp[bal][msk] <= -LL_INF) continue;
			relax(dp2[bal][msk], dp[bal][msk]);
			for(auto& j: unsetBits[msk]) {
				ll magic = 0;
				int addBal = 0;
				if(pos < k) {
					magic = Z[pos].a;
					addBal = 1;
				}
				relax(dp2[bal + addBal][msk | (1<<j)], dp[bal][msk] + Z[pos].b[j] - magic);
			}
			if(pos >= k && bal > 0) {
				relax(dp2[bal - 1][msk], dp[bal][msk] + Z[pos].a);
			}
		}
		for(int i = 0; i <= p; ++i) for(int j = 0; j < (1 << p); ++j) dp[i][j] = dp2[i][j];
	}
	ll answ = 0;
	for(int i = 0; i < k; ++i) answ += Z[i].a;
	answ += dp[0][(1 << p) - 1];
	DBG(dp[0][(1 << p) - 1]);
	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}