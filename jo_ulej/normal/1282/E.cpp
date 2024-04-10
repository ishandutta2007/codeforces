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

struct Triangle {
	pii sides[3];
	int idx, used;
};

const int MAXN = (int)1e5 + 7;
vector<int> g[MAXN];
int used[MAXN];

void dfs(int v, vector<int>& p) {
	used[v] = 1;
	p.push_back(v);
	for(auto& u: g[v]) {
		if(!used[u]) {
			dfs(u, p);
		}
	}
}

void solve() {
	int n = fetch<int>();
	vector<Triangle> a(n - 2);
	map<pii, vector<int>> ids;
	int last = 0;
	for(auto& el: a) {
		++last;
		int a = fetch<int>();
		int b = fetch<int>();
		int c = fetch<int>();

		el.sides[0] = make_pair(a, b);
		el.sides[1] = make_pair(b, c);
		el.sides[2] = make_pair(c, a);
		el.used = 0;
		el.idx = last;
		for(int i = 0; i < 3; ++i) {
			ids[el.sides[i]].push_back(last - 1);
			swap(el.sides[i].first, el.sides[i].second);
			ids[el.sides[i]].push_back(last - 1);
			swap(el.sides[i].first, el.sides[i].second);
		}
	}

	vector<int> ord;
	vector<pii> edges;
	for(int i = 0; i < 3; ++i) edges.push_back(a[0].sides[i]);
	a[0].used = 1;
	ord.push_back(a[0].idx);
	while(!edges.empty()) {
		auto ed = edges.back(); edges.pop_back();
		while(!ids[ed].empty()) {
			int id = ids[ed].back(); ids[ed].pop_back();
			if(a[id].used) continue;
			a[id].used = 1;
			for(int i = 0; i < 3; ++i) edges.push_back(a[id].sides[i]);
			ord.push_back(a[id].idx);
		}
	}

	map<pii, int> has;
	for(auto& el: ord) {
		int pos = el - 1;
		for(int i = 0; i < 3; ++i) {
			auto ed = a[pos].sides[i];
			if(!has.count(ed)) has[ed] = 0;
			has[ed] = has[ed] ^ 1;
			swap(ed.first, ed.second);
			has[ed] = has[ed] ^ 1;
		}
	}

	memset(used, 0, sizeof(used));
	for(int i = 1; i <= n; ++i) {
		g[i].clear();
	}

	for(auto& pr: has) {
		if(pr.second) {
			int v = pr.first.first;
			int u = pr.first.second;
			g[v].push_back(u);

			//cout << "@edge: " << v << ' ' << u << '\n';
		}
	}

	vector<int> perm;
	dfs(1, perm);

	reverse(ord.begin(), ord.end());
	cout << perm << '\n';
	cout << ord << '\n';
}

int main() {
	fast_io();

	int T = fetch<int>();
	while(T--) {
		solve();
	}

	return 0;
}