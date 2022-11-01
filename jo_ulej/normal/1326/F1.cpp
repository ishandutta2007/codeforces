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
const int N = 14;
const int S = (1 << N) + 7;
vector<ll> dp[S][N];
int n, adj[N][N];
int POPCOUNT[S];
vector<int> SetBits[S];
#define getBit(msk, pos) (((msk)>>(pos))&1)
void init() {
	for(int msk = 0; msk < (1 << n); ++msk) for(int i = 0; i < n; ++i) {
		if(getBit(msk, i)) {
			SetBits[msk].emplace_back(i);
			++POPCOUNT[msk];
		}
	}
	for(int msk = 0; msk < (1 << n); ++msk) for(auto& i: SetBits[msk]) dp[msk][i].resize(1 << max(0, POPCOUNT[msk] - 1), 0LL);
}
void solve() {
	n = fetch<int>(); init();
	for(int i = 0; i < n; ++i) {
		auto S = fetch<string>();
		for(int j = 0; j < n; ++j) if(S[j] == '1') adj[i][j] = 1;
	}
	for(int i = 0; i < n; ++i) dp[1 << i][i][0] = 1LL;
	int all = (1 << n) - 1;
	for(int msk = 0; msk < (1 << n); ++msk) for(auto& i: SetBits[msk]) {
		int mxTrace = len(dp[msk][i]);
		for(int trace = 0; trace < mxTrace; ++trace) {
			ll cur = dp[msk][i][trace];
			if(!cur) continue;
			for(auto& j: SetBits[msk ^ all]) {
				int x = adj[i][j];
				dp[msk | (1 << j)][j][(trace << 1) | x] += cur;	
			}
		}
	}
	vector<ll> answ;
	for(int trace = 0; trace < (1 << (n - 1)); ++trace) {
		ll Sum = 0;
		for(int i = 0; i < n; ++i) Sum += dp[all][i][trace];
		answ.emplace_back(Sum);
	}
	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}