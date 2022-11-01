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
	#define DBG(X) cout << #X << "=" << (X) << '\n';
	#define SAY(X) cout << (X) << '\n';
#else
	#define DBG(X)
	#define SAY(X)
#endif
 
using namespace std;

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
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }

const int MAXN = (int)3e5 + 77;
const int BITS = 20;

int n, q, a[MAXN];
int dp[MAXN][BITS], lst[BITS];

void solve() {
	cin >> n >> q;

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for(int i = 0; i < BITS; ++i) {
		lst[i] = NIL;
	}

	for(int v = n - 1; v >= 0; --v) {
		for(int i = 0; i < BITS; ++i) {
			dp[v][i] = n;

			if((a[v] >> i) & 1) {
				dp[v][i] = v;
			} else {
				for(int j = 0; j < BITS; ++j) {
					int u = lst[j];

					if(u != NIL && ((a[v] >> j) & 1) > 0) {
						int local = dp[u][i];
						dp[v][i] = (local < dp[v][i] ? local : dp[v][i]);
					}
				}
			}
		}
		
		for(int i = 0; i < BITS; ++i) {
			if((a[v] >> i) & 1) {
				lst[i] = v;
			}
		}
	}

#ifdef __LOCAL
	for(int v = 0; v < n; ++v) {
		for(int i = 0; i < BITS; ++i) {
			cout << v + 1 << ' ' << i << ' ' << dp[v][i] + 1 << '\n';
		}

		cout << '\n';
	}
#endif

	while(q--) {
		int l = fetch<int>() - 1;
		int r = fetch<int>() - 1;

		int answ = 0;

		for(int i = 0; i < BITS; ++i) {
			if((a[r] >> i) & 1) {
				if(dp[l][i] <= r) {
					answ = 1;
					break;
				}
			}
		}

		cout << (answ ? "Shi\n" : "Fou\n");
	}
}

int main() {
	fast_io();
	solve();

	return 0;
}