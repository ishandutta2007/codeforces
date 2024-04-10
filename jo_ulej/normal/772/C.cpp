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
	#define DEBUG_OUTPUT_ENABLED 1
#else
	#define DEBUG_OUTPUT_ENABLED 0
#endif

#define dout   debug::instance
#define DBG(X) dout << #X << "=" << (X) << '\n';
#define SAY(X) dout << (X) << '\n';

using namespace std;

template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
namespace debug {
	struct DebugStream {
		private:
			bool is_first;
		public:
			DebugStream(bool _is_first): is_first(_is_first) {}
			template<typename T> DebugStream operator<<(const T& value) const {
				if(DEBUG_OUTPUT_ENABLED) {
					if(is_first) cout << "[DBG] ";
					cout << value;
				}
				return DebugStream(false);
			};
	};
	DebugStream instance(true);
};

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
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }
ll GCD(ll x, ll y) {
	return x == 0 ? y : GCD(y % x, x);
}
pll extGCD(ll a, ll b) {
	if(a == 0 || b == 0) {
		return make_pair(1, 1);
	}
	if(a < 0) {
		auto soln = extGCD(-a, b);
		soln.first = -soln.first;
		return soln;
	}
	if(b < 0) {
		auto soln = extGCD(a, -b);
		soln.second = -soln.second;
		return soln;
	}
	if(a < b) {
		auto soln = extGCD(b, a);
		swap(soln.first, soln.second);
		return soln;
	}
	auto soln = extGCD(a%b, b);
	return make_pair(soln.first, -soln.first * (a / b) + soln.second);
}
pll solveEq(ll a, ll b, ll c) {
	ll g = GCD(a, b);
	assert(c % g == 0);
	pll soln = extGCD(a, b);
	soln.first *= c / g;
	soln.second *= c / g;
	return soln;
}
const int MAXN = (int)2e5 + 7;
vector<int> byGCD[MAXN];
int banned[MAXN];
int n, MOD;
int used[MAXN], dp[MAXN], go[MAXN];
int divide(int a, int b) {
	auto soln = solveEq(b, MOD, a);
	ll rez = soln.first;
	rez %= MOD;
	rez += MOD;
	rez %= MOD;
	return rez;
}
void dfsik(int v) {
	used[v] = 1;
	go[v] = NIL;
	if(byGCD[v].empty()) return;
	dp[v] = len(byGCD[v]);
	int change = 0;
	if(v > 0) for(int u = 2 * v; u < MOD; u += v) {
		if(!used[u]) dfsik(u);
		if(dp[u] > change) {
			change = dp[u];
			go[v] = u;
		}
	}
	if(!used[0]) dfsik(0);
	if(dp[0] > change && v != 0) {
		change = dp[0];
		go[v] = 0;
	}
	dp[v] += change;
}
int answ[MAXN], answSz = 0;
void solve() {
	cin >> n >> MOD;
	for(int i = 0; i < n; ++i) {
		int x = fetch<int>();
		banned[x] = 1;
	}
	for(int i = 0; i < MOD; ++i) if(!banned[i]) {
		int g = GCD(i, MOD) % MOD;
		byGCD[g].push_back(i);
	}
	int start = 0;
	for(int i = 0; i < MOD; ++i) {
		if(!used[i]) dfsik(i);
		if(dp[i] > dp[start]) start = i;
	}
	for(int cur = start; cur != NIL; cur = go[cur]) {
		for(auto& el: byGCD[cur]) answ[answSz++] = el;
	}
	for(int i = answSz - 1; i > 0; --i) answ[i] = divide(answ[i], answ[i - 1]);
	cout << answSz << '\n';
	for(int i = 0; i < answSz; ++i) cout << answ[i] << ' ';
	cout << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}