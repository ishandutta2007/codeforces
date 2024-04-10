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

const int MAXN = 111;
char G[MAXN][MAXN];
int answ[MAXN][MAXN];
string A;
int r, c, k;

void solve() {
	int cntr = 0;
	cin >> r >> c >> k;

	for(int i = 0; i < r; ++i) {
		auto line = fetch<string>();

		for(int j = 0; j < c; ++j) {
			G[i][j] = line[j];
			answ[i][j] = NIL;

			cntr += (G[i][j] == 'R');
		}
	}

	int small = cntr / k;
	int big   = small + 1;
	int cnt_big = cntr % k;
	int cnt_small = k - cnt_big;

	DBG(cntr); DBG(big); DBG(small);
	DBG(cnt_big); DBG(cnt_small);

	vector<pii> ord;

	for(int i = 0; i < r; ++i) {
		if(i & 1) {
			for(int j = 0; j < c; ++j) {
				ord.emplace_back(i, j);
			}
		} else {
			for(int j = c - 1; j >= 0; --j) {
				ord.emplace_back(i, j);
			}
		}
	}

	reverse(ord.begin(), ord.end());

	for(int idx = 0; idx < cnt_big; ++idx) {
		int cur = 0;

		while(cur != big) {
			auto last = ord.back();
			ord.pop_back();

			cur += (G[last.first][last.second] == 'R');
			answ[last.first][last.second] = idx;
		}
	}

	for(int idx = cnt_big; idx < k; ++idx) {
		int cur = 0;

		while(cur != small) {
			auto last = ord.back();
			ord.pop_back();

			cur += (G[last.first][last.second] == 'R');
			answ[last.first][last.second] = idx;
		}
	}

	for(int i = 0; i < r; ++i) {
		string line(c, '$');

		for(int j = 0; j < c; ++j) {
			int code = answ[i][j];

			if(code < 0) {
				code = k - 1;
			}

			line[j] = A[code];
		}

		cout << line << '\n';
	}

#ifdef __LOCAL
	int mx = -INT_INF, mn = INT_INF;

	for(int idx = 0; idx < k; ++idx) {
		int sum = 0;

		for(int i = 0; i < r; ++i) {
			for(int j = 0; j < c; ++j) {
				if(answ[i][j] == idx) {
					sum += (G[i][j] == 'R');
				}
			}
		}

		mx = max(mx, sum);
		mn = min(mn, sum);
		cout << idx << ' ' << sum << '\n';
	}

	assert(mx - mn <= 1);
#endif
}

int main() {
	fast_io();

	for(char chr = 'a'; chr <= 'z'; ++chr) {
		A.push_back(chr);
	}

	for(char chr = 'A'; chr <= 'Z'; ++chr) {
		A.push_back(chr);
	}

	for(char chr = '0'; chr <= '9'; ++chr) {
		A.push_back(chr);
	}

	int T = fetch<int>();

	while(T--) {
		solve();
	}

	return 0;
}