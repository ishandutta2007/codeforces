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

const int MAXN = 100;
int G[MAXN][MAXN];
int n, m;

void upd(int& x, int y) {
	x = (y < x ? y : x);
}

void solve() {
	cin >> n >> m;
	int answ = INT_INF;

	for(int i = 0; i < n; ++i) {
		auto S = fetch<string>();

		for(int j = 0; j < m; ++j) {
			G[i][j] = (S[j] == 'A');
		}
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(G[i][j] == 1) {
				upd(answ, 4);

				if(i == 0 || i == n - 1 || j == 0 || j == m - 1) {
					upd(answ, 3);
				}

				if((i == 0 || i == n - 1) && (j == 0 || j == m - 1)) {
					upd(answ, 2);
				}
			}
		}
	}

	for(int i = 0; i < n; ++i) {
		int ok = 1;

		for(int j = 0; j < m; ++j) {
			if(G[i][j] == 0) {
				ok = 0;
				break;
			}
		}

		if(ok) {
			upd(answ, 2);

			if(i == 0 || i == n - 1) {
				upd(answ, 1);
			}
		}
	}

	for(int j = 0; j < m; ++j) {
		int ok = 1;

		for(int i = 0; i < n; ++i) {
			if(G[i][j] == 0) {
				ok = 0;
				break;
			}
		}

		if(ok) {
			upd(answ, 2);

			if(j == 0 || j == m - 1) {
				upd(answ, 1);
			}
		}
	}

	int all = 1;

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(G[i][j] == 0) {
				all = 0;
				break;
			}
		}
	}

	if(all) {
		upd(answ, 0);
	}

	if(answ > 4) {
		cout << "MORTAL\n";	
	} else {
		cout << answ << '\n';
	}
}

int main() {
	fast_io();

	int T = fetch<int>();

	while(T--) {
		solve();
	}

	return 0;
}