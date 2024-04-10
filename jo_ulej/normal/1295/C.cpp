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

const int A = 30;
vector<int> pos[A];

void solve() {
	for(int i = 0; i < A; ++i) pos[i].clear();
	auto S = fetch<string>();
	auto T = fetch<string>();
	for(int i = 0; i < len(S); ++i) {
		int code = S[i] - 'a';
		pos[code].push_back(i);
	}
	int cur = NIL;
	int answ = 1;
	for(auto& ch: T) {
		int code = ch - 'a';
		if(pos[code].empty()) {
			cout << NIL << '\n';
			return;
		}
		auto iter = upper_bound(pos[code].begin(), pos[code].end(), cur);
		if(iter == pos[code].end()) {
			++answ;
			cur = NIL;
			iter = pos[code].begin();
		}
		cur = *iter;
	}
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