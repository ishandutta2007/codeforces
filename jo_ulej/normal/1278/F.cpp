#pragma GCC optimize("Ofast,unroll-loops")

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

const int LOG = 31;
const int MAXK = 5077;
const int MOD  = 998244353;

int add(int x, int y) {
	return (x + y >= MOD ? x + y - MOD : x + y);
}

int sub(int x, int y) {
	return (x - y < 0 ? x - y + MOD : x - y);
}

int mult(int x, int y) {
	return (x * 1LL * y) % MOD;
}

int binpow(int x, int y) {
	if(y == 0 || x == 1) return 1;
	if(x == 0)           return 0;
	int rez = binpow(x, y >> 1);
	rez = mult(rez, rez);
	if(y & 1) rez = mult(rez, x);
	return rez;
}

int divide(int x, int y) {
	return mult(x, binpow(y, MOD - 2));
}

const ll MOD2 = MOD * 1LL * MOD;

int pw[LOG][MAXK], rez[MAXK], temp[MAXK];
ll g[MAXK];

void solve() {
	int n = fetch<int>();
	int m = fetch<int>();
	int k = fetch<int>();
	
	vector<int> F(k + 1, 1), A(k + 1, 0);
	A[0] = 1;

	for(int i = 1; i <= k; ++i) {
		F[i] = mult(F[i - 1], i);
	}

	for(int i = 1; i <= k; ++i) {
		A[i] = divide(1, F[i]);
		A[i] = divide(A[i], m);
	}

	for(int i = 0; i <= k; ++i) {
		pw[0][i] = A[i];
	}

	rez[0] = 1;

	for(int log = 0; log < LOG - 1; ++log) {
		memset(g, 0, sizeof(g));
		for(int i = 0; i < MAXK; ++i) {
			for(int j = 0; i + j < MAXK; ++j) {
				//pw[log + 1][i + j] = add(pw[log + 1][i + j], mult(pw[log][i], pw[log][j]));
				g[i + j] += pw[log][i] * 1LL * pw[log][j];

				if(g[i + j] >= MOD2) {
					g[i + j] -= MOD2;
				}
			}
		}

		for(int i = 0; i < MAXK; ++i) {
			pw[log + 1][i] = g[i] % MOD;
		}
	}

	for(int log = 0; log < LOG; ++log) {
		if((n >> log) & 1) {
			memset(g, 0, sizeof(g));
			for(int i = 0; i < MAXK; ++i) {
				for(int j = 0; i + j < MAXK; ++j) {
					//temp[i + j] = add(temp[i + j], mult(pw[log][i], rez[j]));
					g[i + j] += pw[log][i] * 1LL * rez[j];

					if(g[i + j] >= MOD2) {
						g[i + j] -= MOD2;
					}
				}
			}

			for(int i = 0; i < MAXK; ++i) {
				rez[i] = g[i] % MOD;
			}
		}
	}

	int answ = rez[k];
	answ = mult(answ, F[k]);
	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}