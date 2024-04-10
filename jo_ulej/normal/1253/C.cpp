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

const int MAXN = (int)2e5 + 77;
ll a[MAXN], b[MAXN], pref[MAXN], dp[MAXN];
int n, m;

ll get(int l, int r) {
	return (l == 0 ? pref[r] : pref[r] - pref[l - 1]);
}

void solve() {
	cin >> n >> m;

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}	

	sort(a, a + n);
	pref[0] = a[0];

	for(int i = 1; i < n; ++i) {
		pref[i] = pref[i - 1] + a[i];
	}

	for(int r = 0; r < n; ++r) {
		int take = min(r + 1, m);
		int l = r - take + 1;

		dp[r] += get(l, r);

		if(l > 0) {
			dp[r] += dp[l - 1];
			dp[r] += get(0, l - 1);
		}
	}

	for(int i = 0; i < n; ++i) {
		cout << dp[i] << ' ';
	}

	cout << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}