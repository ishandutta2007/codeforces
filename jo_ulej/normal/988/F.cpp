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

const int MAXN = 2177;

ll dp[MAXN][MAXN];
ll p[MAXN];
int rain[MAXN];
int a, n, m;

vector<int> masses;

void solve() {
	cin >> a >> n >> m;

	for(int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;

		for(int j = l; j < r; ++j) {
			rain[j] = 1;
		}
	}

	for(int j = 0; j < m; ++j) {
		int x, mass;
		cin >> x >> mass;

		if(p[x] == 0) {
			p[x] = mass;
		} else if(mass < p[x]) {
			p[x] = mass;
		}
	}

	masses.push_back(0);

	for(int pos = 0; pos <= a; ++pos) {
		masses.push_back(p[pos]);
	}

	sort(masses.begin(), masses.end());
	masses.erase(unique(masses.begin(), masses.end()), masses.end());

	for(int i = 0; i < MAXN; ++i) {
		for(int j = 0; j < MAXN; ++j) {
			dp[i][j] = LL_INF;
		}
	}

	dp[0][0] = 0;

	for(int i = 0; i < a; ++i) {
		for(int j = 0; j < len(masses); ++j) {
			ll cur = masses[j];

			if(!rain[i] || cur > 0) {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + cur);
			}

			if(!rain[i] || p[i] > 0) {
				int k = lower_bound(masses.begin(), masses.end(), p[i]) - masses.begin();
				dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + p[i]);
			}

			if(!rain[i]) {
				dp[i + 1][0] = min(dp[i + 1][0], dp[i][j]);
			}
		}
	}

	ll answ = LL_INF;

	for(int j = 0; j < len(masses); ++j) {
		answ = min(answ, dp[a][j]);
	}

	cout << (answ == LL_INF ? NIL : answ) << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}