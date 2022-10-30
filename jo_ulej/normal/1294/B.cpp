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
	#define DBG(X) cout << "[DBG] " << #X << "=" << (X) << '\n';
	#define SAY(X) cout << "[SAY] " << (X) << '\n';
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
	vector<pair<int, pii>> pts;
	for(int i = 0; i < n; ++i) {
		int x = fetch<int>();
		int y = fetch<int>();
		pts.emplace_back(x + y, make_pair(x, y));
	}
	sort(pts.begin(), pts.end());
	for(int i = 0; i < n - 1; ++i) {
		if(pts[i].first == pts[i + 1].first) {
			cout << "NO\n";
			return;
		}
		if(pts[i + 1].second.first < pts[i].second.first) {
			cout << "NO\n";
			return;
		}
		if(pts[i + 1].second.second < pts[i].second.second) {
			cout << "NO\n";
			return;
		}
	}
	string answ;
	for(int i = 0; i < n; ++i) {
		int dx = (i == 0 ? pts[i].second.first : pts[i].second.first - pts[i - 1].second.first);
		int dy = (i == 0 ? pts[i].second.second : pts[i].second.second - pts[i - 1].second.second);
		for(; dx > 0; --dx) answ.push_back('R');
		for(; dy > 0; --dy) answ.push_back('U');
	}

	cout << "YES\n";
	cout << answ << '\n';
}

int main() {
	fast_io();

	int T = fetch<int>();
	while(T--) {
		solve();
	}

	return 0;
}