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

const int INT_INF = (int)(1e9);
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

const int MAXN = (int)2e5 + 7;
vector<int> g[MAXN];
int n, root;
int dp1[MAXN], dp2[MAXN];
int who1[MAXN];
pii who2[MAXN];
int depth[MAXN];

int answ = -INT_INF;
int a = NIL, b = NIL, c = NIL;

void dfs(int v, int p) {
	depth[v] = (p == NIL ? 0 : depth[p] + 1);
	dp1[v] = 0;
	who1[v] = v;
	for(auto& u: g[v]) {
		if(u != p) {
			dfs(u, v);
			if(dp1[u] + 1 > dp1[v]) {
				dp1[v] = dp1[u] + 1;
				who1[v] = who1[u];
			}
		}
	}

	vector<pii> prs;
	for(auto& u: g[v]) {
		if(u != p) {
			prs.emplace_back(dp1[u], who1[u]);
		}
	}

	sort(prs.begin(), prs.end());
	reverse(prs.begin(), prs.end());
	if(len(prs) >= 3) {
		int sum = 3 + prs[0].first + prs[1].first + prs[2].first;
		if(sum > answ) {
			DBG(v + 1);
			answ = sum;
			a = prs[0].second;
			b = prs[1].second;
			c = prs[2].second;
		}
	}
	if(len(prs) >= 2) {
		dp2[v] = 2 + prs[0].first + prs[1].first;
		who2[v] = make_pair(prs[0].second, prs[1].second);
	} else {
		dp2[v] = -INT_INF;
		who2[v] = make_pair(NIL, NIL);
	}

	for(auto& u: g[v]) {
		if(u != p) {
			if(dp2[u] + 1 > dp2[v]) {
				dp2[v] = dp2[u] + 1;
				who2[v] = who2[u];
			}
		}
	}

	int sum = depth[v] + dp2[v];
	if(sum > answ && who2[v].first != NIL && who2[v].second != NIL) {
		answ = sum;
		a = root;
		b = who2[v].first;
		c = who2[v].second;
	}

	set<pii> setik;
	for(auto& pr: prs) setik.insert(pr);
	for(auto& u: g[v]) {
		if(u != p) {
			setik.erase(make_pair(dp1[u], who1[u]));
			if(len(setik) >= 1) {
				auto iter = prev(setik.end());
				int sum = 2 + dp2[u] + iter->first;
				if(sum > answ && who2[u].first != NIL && who2[u].second != NIL) {
					DBG(sum);
					answ = sum;
					a = who2[u].first;
					b = who2[u].second;
					c = iter->second;
				}
			}
			setik.emplace(dp1[u], who1[u]);
		}
	}

	for(auto& u: g[v]) {
		if(u != p) {
			int sum = 1 + dp1[u];
			if(sum > answ && who1[u] != u) {
				answ = sum;
				a = v;
				b = u;
				c = who1[u];
			}
		}
	}
}

void solve() {
	cin >> n;
	for(int i = 0; i < n - 1; ++i) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	root = n - 1;
	dfs(root, NIL);
#ifdef __LOCAL
	for(int i = 0; i < n; ++i) {
		cout << "@vertex " << i + 1 << ": " << dp2[i] << '\n';
	}
#endif

	assert(a != NIL); assert(b != NIL); assert(c != NIL);
	assert(a != b); assert(b != c); assert(c != a);
	assert(answ > 0);
	cout << answ << '\n';
	cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}