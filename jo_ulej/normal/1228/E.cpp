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

const int MOD = (int)1e9 + 7;
const int MAXN = 300;

int add(int x, int y) {
	return (x + y >= MOD ? x + y - MOD : x + y);
}

int sub(int x, int y) {
	return (x - y < 0 ? x - y + MOD : x - y);
}

int mult(int x, int y) {
	return (x * 1LL * y) % MOD;
}

int dp[MAXN][MAXN]; // dp[i][j]
int used[MAXN][MAXN];
int C[MAXN][MAXN]; // C[set][subset]
int pwK[MAXN], pwK1[MAXN];
int n, k;

void precalc() {
	pwK[0] = 1;
	pwK1[0] = 1;

	for(int i = 0; i < MAXN - 1; ++i) {
		pwK[i + 1] = mult(pwK[i], k);
		pwK1[i + 1] = mult(pwK1[i], k - 1);
	}

	for(int set = 0; set < MAXN; ++set) {
		C[set][0] = C[set][set] = 1;

		for(int subset = 1; subset < set; ++subset) {
			C[set][subset] = add(C[set - 1][subset], C[set - 1][subset - 1]);
		}
	}
}

void solve() {
	cin >> n >> k;
	precalc();

	if(k == 1) {
		cout << "1\n";
		return;
	}

	dp[0][n] = 1;
	used[0][n] = 1;

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= n; ++j) {
			if(!used[i][j]) {
				continue;
			}

			if(i == 0 && j < n) {
				continue;
			}

			for(int kill = 0; kill <= j; ++kill) {
				if(kill == 0 && j == n) {
					continue;
				}

				int local = dp[i][j];
				DBG(i); DBG(j); DBG(kill);
				DBG(local);

				local = mult(local, C[j][kill]);
				DBG(local);
				local = mult(local, pwK1[j - kill]);
				DBG(local);

				if(kill > 0) {
					local = mult(local, pwK[n - j]);
				} else {
					local = mult(local, sub(pwK[n - j], pwK1[n - j]));
				}

				DBG(local);

				dp[i + 1][j - kill] = add(dp[i + 1][j - kill], local);
				used[i + 1][j - kill] = 1;
			}
		}
	}

#ifdef __LOCAL
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= n; ++j) {
			cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
		}
	}
#endif

	cout << dp[n][0] << '\n';
}

int main() {
	fast_io();

	solve();

	return 0;
}