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

const int MOD  = 998244353;
const int MAXN = 3607;

int add(int x, int y) {
	return (x + y >= MOD ? x + y - MOD : x + y);
}

int mult(int x, int y) {
	return (x * 1LL * y) % MOD;
}

int binpow(int x, int y) {
	if(y == 0 || x == 1) {
		return 1;
	}

	if(x == 0) {
		return 0;
	}

	int rez = binpow(x, y / 2);
	rez = mult(rez, rez);

	if(y & 1) {
		rez = mult(rez, x);
	}

	return rez;
}

int divide(int x, int y) {
	return mult(x, binpow(y, MOD - 2));
}

int n, H, W;
int row[MAXN], col[MAXN];
int dpR[MAXN][MAXN], dpC[MAXN][MAXN];
int R[MAXN][MAXN], C[MAXN][MAXN];
int fact[MAXN * MAXN], inv_fact[MAXN * MAXN];

int cnt_row, cnt_col;

void precalc() {
	fact[0] = 1;

	for(int i = 1; i < MAXN * MAXN; ++i) {
		fact[i] = mult(i, fact[i - 1]);
	}

	inv_fact[MAXN * MAXN - 1] = divide(1, fact[MAXN * MAXN - 1]);

	for(int i = MAXN * MAXN - 2; i >= 0; --i) {
		inv_fact[i] = mult(inv_fact[i + 1], i + 1);
	}
}

int choose(int k, int n) {
	if(k > n) {
		return 0;
	}

	int rez = fact[n];
	rez = mult(rez, inv_fact[k]);
	rez = mult(rez, inv_fact[n - k]);

	return rez;
}

void solve() {
	cin >> H >> W >> n;

	for(int i = 0; i < H; ++i) {
		row[i] = 1;
	}

	for(int i = 0; i < W; ++i) {
		col[i] = 1;
	}

	for(int i = 0; i < n; ++i) {
		int r1 = fetch<int>() - 1;
		int c1 = fetch<int>() - 1;
		int r2 = fetch<int>() - 1;
		int c2 = fetch<int>() - 1;

		row[r1] = 0;
		row[r2] = 0;

		col[c1] = 0;
		col[c2] = 0;
	}

	for(int i = 0; i < H; ++i) {
		cnt_row += row[i];
	}

	for(int i = 0; i < W; ++i) {
		cnt_col += col[i];
	}

	DBG(cnt_row); DBG(cnt_col);

#ifdef __LOCAL
	cout << "row: ";

	for(int i = 0; i < H; ++i) {
		cout << row[i];
	}

	cout << '\n';
	cout << "col: ";

	for(int i = 0; i < W; ++i) {
		cout << col[i];
	}

	cout << '\n';
#endif

	dpR[0][0] = dpC[0][0] = 1;

	for(int i = 0; i < H; ++i) {
		for(int j = 0; j <= H; ++j) {
			dpR[i + 1][j] = add(dpR[i + 1][j], dpR[i][j]);

			if(i + 1 < H && row[i] && row[i + 1]) {
				dpR[i + 2][j + 1] = add(dpR[i + 2][j + 1], dpR[i][j]);
			}
		}
	}

	for(int i = 0; i < W; ++i) {
		for(int j = 0; j <= W; ++j) {
			dpC[i + 1][j] = add(dpC[i + 1][j], dpC[i][j]);

			if(i + 1 < W && col[i] && col[i + 1]) {
				dpC[i + 2][j + 1] = add(dpC[i + 2][j + 1], dpC[i][j]);
			}
		}
	}

	for(int i = 0; i <= H; ++i) {
		for(int j = 0; j <= H; ++j) {
			if(2 * i + j <= cnt_row) {
				R[i][j] = mult(dpR[H][i], choose(j, cnt_row - 2 * i));
			}
		}
	}

	for(int i = 0; i <= W; ++i) {
		for(int j = 0; j <= W; ++j) {
			if(2 * i + j <= cnt_col) {
				C[i][j] = mult(dpC[W][i], choose(j, cnt_col - 2 * i));
			}
		}
	}

	int answ = 0;

	for(int h = 0; h < MAXN; ++h) {
		for(int w = 0; w < MAXN; ++w) {
			int part = mult(R[h][w], C[w][h]);
			part = mult(part, mult(fact[w], fact[h]));

			answ = add(answ, part);
		}
	}

	cout << answ << '\n';
}

int main() {
	fast_io();

	precalc();
	solve();

	return 0;
}