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

const int INT_INF = (int)(1e7);
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

const int MAXN = 107;
int a[MAXN], n;
int used[MAXN], cnt[2];
int dp[MAXN][MAXN][MAXN][2];

void upd(int& x, int y) {
	x = (y < x ? y : x);
}

void solve() {
	cin >> n; for(int i = 0; i < n; ++i) a[i] = fetch<int>() - 1;
	for(int i = 0; i < n; ++i) if(a[i] >= 0) used[a[i]] = 1;
	for(int i = 0; i < n; ++i) if(!used[i]) ++cnt[i & 1];
	for(int i = 0; i <= n; ++i) for(int e = 0; e <= n; ++e) for(int o = 0; o <= n; ++o) for(int l = 0; l < 2; ++l) dp[i][e][o][l] = INT_INF;
	dp[0][cnt[0]][cnt[1]][0] = 0;
	dp[0][cnt[0]][cnt[1]][1] = 0;
	for(int i = 0; i < n; ++i) {
		for(int e = 0; e <= n; ++e) {
			for(int o = 0; o <= n; ++o) {
				for(int l = 0; l < 2; ++l) {
					if(dp[i][e][o][l] >= INT_INF) continue;
					if(a[i] >= 0) {
						upd(dp[i + 1][e][o][a[i] & 1], dp[i][e][o][l] + (l != (a[i] & 1)));
					} else {
						if(e > 0) {
							upd(dp[i + 1][e - 1][o][0], dp[i][e][o][l] + (l != 0));
						}

						if(o > 0) {
							upd(dp[i + 1][e][o - 1][1], dp[i][e][o][l] + (l != 1));
						}
					}
				}
			}
		}
	}

	cout << min(dp[n][0][0][0], dp[n][0][0][1]) << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}