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

pii go[4][4][26];
const string bad1 = "one", bad2 = "two";

int match(const string& s, const string& t) {
	for(int pref = min(len(s), len(t)); pref >= 0; --pref) {
		int ok = 1;

		for(int i = 0; i < pref; ++i) {
			if(s[len(s) - pref + i] != t[i]) {
				ok = 0;
				break;
			}
		}

		if(ok) {
			return pref;
		}
	}

	assert(false);
}

void init() {
	for(int a = 0; a < 4; ++a) {
		for(int b = 0; b < 4; ++b) {
			for(char chr = 'a'; chr <= 'z'; ++chr) {
				int code = chr - 'a';

				{
					string suff1;

					for(int i = 0; i < a; ++i) {
						suff1.push_back(bad1[i]);
					}

					suff1.push_back(chr);
					go[a][b][code].first = match(suff1, bad1);
				}

				{
					string suff2;

					for(int i = 0; i < b; ++i) {
						suff2.push_back(bad2[i]);
					}

					suff2.push_back(chr);
					go[a][b][code].second = match(suff2, bad2);
				}
			}
		}
	}
}

const int MAXN = (int)2e5;
int dp[MAXN][4][4];
int took[MAXN][4][4];
pii prv[MAXN][4][4];

bool upd(int& x, int y) {
	if(y < x) {
		x = y;
		return true;
	} else {
		return false;
	}
}

void solve() {
	auto S = fetch<string>();
	int n = len(S);

	for(int i = 0; i <= n; ++i) {
		for(int a = 0; a < 4; ++a) {
			for(int b = 0; b < 4; ++b) {
				dp[i][a][b] = INT_INF;
				took[i][a][b] = NIL;
				prv[i][a][b] = make_pair(NIL, NIL);
			}
		}
	}

	dp[0][0][0] = 0;

	for(int i = 0; i < n; ++i) {
		for(int a = 0; a < 3; ++a) {
			for(int b = 0; b < 3; ++b) {
				if(upd(dp[i + 1][a][b], dp[i][a][b] + 1)) {
					took[i + 1][a][b] = 0;
					prv[i + 1][a][b] = make_pair(a, b);
				}

				int code = S[i] - 'a';
				int a2 = go[a][b][code].first;
				int b2 = go[a][b][code].second;

				if(upd(dp[i + 1][a2][b2], dp[i][a][b])) {
					took[i + 1][a2][b2] = 1;
					prv[i + 1][a2][b2] = make_pair(a, b);
				}
			}
		}
	}

	int answ = INT_INF;
	int A = NIL, B = NIL;
	int cur = n;

	for(int a = 0; a < 3; ++a) {
		for(int b = 0; b < 3; ++b) {
			if(upd(answ, dp[n][a][b])) {
				A = a;
				B = b;
			}
		}
	}

	vector<int> pos;

	while(cur > 0) {
		if(!took[cur][A][B]) {
			pos.push_back(cur);
		}

		int a2 = prv[cur][A][B].first;
		int b2 = prv[cur][A][B].second;
		--cur;

		A = a2;
		B = b2;
	}

	reverse(pos.begin(), pos.end());
	cout << answ << '\n';
	cout << pos << '\n';
}

int main() {
	fast_io();
	init();

	int T = fetch<int>();

	while(T--) {
		solve();
	}

	return 0;
}