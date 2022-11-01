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
#else
	#define DBG(X)
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
template<typename T> inline void goodbye(const T& val) { cout << val << endl; exit(0); }

const int MOD  = 998244353;
const int MAXN = (int)1e6 + 777;

int add(int x, int y) {
	return (x + y >= MOD ? x + y - MOD : x + y);
}

int mult(int x, int y) {
	return (x * 1LL * y) % MOD;
}

int n;
int dp[MAXN][2]; // dp[sz][parity_of_root]

void solve() {
	cin >> n;

	dp[0][0] = 1;
	dp[0][1] = 1;

	for(int i = 1; i <= n; ++i) {
		if(i & 1) {
			int j = (i - 1) / 2;
			
			int p = (i + 1) / 2;
			p &= 1;

			dp[i][p] = add(dp[i][p], mult(dp[j][p ^ 1], dp[j][p ^ 1 ^ (j & 1)]));
		} else {
			int j1 = (i - 1) / 2;
			int j2 = i - 1 - j1;

			if(i % 4 != 0) {
				swap(j1, j2);
			}

			dp[i][0] = add(dp[i][0], mult(dp[j1][1], dp[j2][0]));
			dp[i][1] = add(dp[i][1], mult(dp[j2][0], dp[j1][0]));
		}
	}

#ifdef __LOCAL
	for(int i = 0; i <= n; ++i) {
		cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << '\n';
	}
#endif

	cout << add(dp[n][0], dp[n][1]) << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}