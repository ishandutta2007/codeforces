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
//inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }

const int MAXN = (int)107;
vector<pii> g[MAXN];

void add_edge(int v, int u, int s) {
#ifdef __LOCAL
	cout << "@edge: " << v << ' ' << u << ' ' << s << endl;
#endif

	g[v].emplace_back(u, s);
	g[u].emplace_back(v, s);
}

void proc(int l, int r) {
	cout << "? " << l + 1 << ' ' << r + 1 << endl;
	int sz = r - l + 1;
	int cnt = (sz * (sz + 1)) / 2;
	vector<int> sum(sz + 1, 0);

	for(int i = 0; i < cnt; ++i) {
		auto S = fetch<string>();
		for(auto& el: S) {
			int code = (int)(el - 'a');
			sum[len(S)] += code;
		}
	}

	DBG(sum);
	int fsum = sum[sz];
	for(int i = 0; i <= sz; ++i) {
		sum[i] = (false ? 1 : sz - i + 1) * fsum - sum[i];
	}

	DBG(sum);
	reverse(sum.begin(), sum.end());
	for(int i = sz; i > 0; --i) {
		sum[i] -= sum[i - 1];
	}
	
	DBG(sum);
	for(int i = sz; i > 0; --i) {
		sum[i] -= sum[i - 1];
	}
	
	DBG(sum);
	for(int i = l; i <= r; ++i) {
		int j = r + l - i;
		if(j >= i) {
			int s = sum[i - l + 1];
			add_edge(i, j, s);
		}
	}
}

int used[MAXN], val[MAXN];
void dfs(int v) {
	used[v] = 1;
	for(auto& ed: g[v]) {
		int u = ed.first;
		int s = ed.second;

		if(!used[u]) {
			val[u] = s - val[v];
			dfs(u);
		}
	}
}

void solve() {
	int n = fetch<int>();
	proc(0, n - 1);
	if(n > 1) proc(0, n - 2);
	memset(val, NIL, sizeof(val));
	for(int i = 0; i < n; ++i) {
		for(auto& ed: g[i]) {
			int j = ed.first;
			int sum = ed.second;

			if(i == j) {
				assert(sum % 2 == 0);
				val[i] = sum / 2;
			}
		}
	}

	for(int i = 0; i < n; ++i) {
		if(val[i] != NIL) {
			dfs(i);
			break;
		}
	}

	for(int i = 0; i < n; ++i) {
		assert(val[i] != NIL);
	}

	string answ(n, '%');
	for(int i = 0; i < n; ++i) answ[i] = 'a' + val[i];
	cout << "! " << answ << endl;
}

int main() {
	//fast_io();
	solve();

	return 0;
}