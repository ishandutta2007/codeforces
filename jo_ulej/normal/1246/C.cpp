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
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }

const int MOD = (int)1e9 + 7;
const int MAXN = 2077;

int add(int x, int y) {
	return (x + y >= MOD ? x + y - MOD : x + y);
}

int sub(int x, int y) {
	return (x - y < 0 ? x - y + MOD : x - y);
}

int mult(int x, int y) {
	return (x * 1LL * y) % MOD;
}

int A[MAXN][MAXN], dp[MAXN][MAXN][2]; // 1 -- last=hor, 0 -- last=vert
int H[MAXN][MAXN], V[MAXN][MAXN];
int n, m;

void prepare() {
	dp[0][0][0] = 1;
	dp[0][0][1] = 1;

	for(int i = n - 1; i >= 0; --i) {
		for(int j = m - 1; j >= 0; --j) {
			H[i][j] = V[i][j] = A[i][j];

			if(j != m - 1) {
				H[i][j] += H[i][j + 1];
			}

			if(i != n - 1) {
				V[i][j] += V[i + 1][j];
			}
		}
	}
}

int curH[MAXN], curV[MAXN];
int dH[MAXN][MAXN], dV[MAXN][MAXN];

void go(int i, int j) {
	curH[i] = add(curH[i], dH[i][j]);
	curV[j] = add(curV[j], dV[i][j]);

	dp[i][j][1] = add(dp[i][j][1], curH[i]);
	dp[i][j][0] = add(dp[i][j][0], curV[j]);
}

void addH(int i, int jL, int jR, int x) {
	if(jL > jR) {
		return;
	}

	dH[i][jL] = add(dH[i][jL], x);
	dH[i][jR + 1] = sub(dH[i][jR + 1], x);
}

void addV(int iL, int iR, int j, int x) {
	if(iL > iR) {
		return;
	}

	dV[iL][j] = add(dV[iL][j], x);
	dV[iR + 1][j] = sub(dV[iR + 1][j], x);
}

void solve() {
	cin >> n >> m;

	for(int i = 0; i < n; ++i) {
		auto line = fetch<string>();

		for(int j = 0; j < m; ++j) {
			A[i][j] = (line[j] == 'R');
		}
	}

	if(n == 1 && m == 1) {
		cout << "1\n";
		return;
	}

	prepare();

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			int cntH = (j == m - 1 ? 0 : H[i][j + 1]);
			int cntV = (i == n - 1 ? 0 : V[i + 1][j]);
			go(i, j);

			/*for(int j2 = j + 1; j2 <= m - 1 - cntH; ++j2) {
				dp[i][j2][1] = add(dp[i][j2][1], dp[i][j][0]);
			}*/

			addH(i, j + 1, m - 1 - cntH, dp[i][j][0]);

			/*for(int i2 = i + 1; i2 <= n - 1 - cntV; ++i2) {
				dp[i2][j][0] = add(dp[i2][j][0], dp[i][j][1]);
			}*/

			addV(i + 1, n - 1 - cntV, j, dp[i][j][1]);
		}
	}

#ifdef __LOCAL
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			for(int last = 0; last < 2; ++last) {
				cout << i << ' ' << j << ' ' << last << ' ' << dp[i][j][last] << '\n';
			}
		}
	}
#endif

	cout << add(dp[n - 1][m - 1][0], dp[n - 1][m - 1][1]) << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}