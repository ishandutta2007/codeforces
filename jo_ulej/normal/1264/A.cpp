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

void solve() {
	int n = fetch<int>();
	auto a = fetch_vec<int>(n);
	vector<int> b;

	for(int i = 0; i < n;) {
		int j = i;

		while(j + 1 < n && a[j + 1] == a[i]) {
			++j;
		}

		b.push_back(j - i + 1);
		i = j + 1;
	}

	int cnt = len(b);
	int sm = 0, i = 0;

	while(i < cnt && 2 * (sm + b[i]) <= n) {
		sm += b[i];
		++i;
	}

	if(i < 3) {
		cout << "0 0 0\n";
		return;
	}

	vector<int> pref(cnt + 1, 0);

	for(int j = 1; j <= cnt; ++j) {
		pref[j] = pref[j - 1] + b[j - 1];
	}

	for(int cntS = 1; cntS < i; ++cntS) {
		int cntB = i - 1 - cntS;
		int G = pref[1];
		int S = pref[cntS + 1] - pref[1];
		int B = pref[i] - S - G;

		if(G < S && G < B && 2 * (G + B + S) <= n) {
			cout << G << ' ' << S << ' ' << B << '\n';
			return;
		}
	}

	cout << "0 0 0\n";
}

int main() {
	fast_io();

	int T = fetch<int>();

	while(T--) {
		solve();
	}

	return 0;
}