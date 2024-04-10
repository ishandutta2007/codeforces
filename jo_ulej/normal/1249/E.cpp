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
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }

const int MAXN = (int)4e5 + 777;

vector<pair<int, ll>> g[MAXN];
int n;
ll a[MAXN], b[MAXN], c;
ll dist[MAXN];

void add_edge(int v, int u, ll weight) {
	g[v].emplace_back(u, weight);
}

void solve() {
	cin >> n >> c;

	for(int i = 0; i < n - 1; ++i) {
		cin >> a[i];
	}

	for(int j = 0; j < n - 1; ++j) {
		cin >> b[j];
	}

	for(int i = 0; i < n - 1; ++i) {
		add_edge(i, i + 1, a[i]);
		add_edge(i + 1, i, a[i]);

		add_edge(i + n, i + 1 + n, b[i]);
		add_edge(i + 1 + n, i + n, b[i]);
	}

	for(int i = 0; i < n; ++i) {
		add_edge(i, i + n, c);
		add_edge(i + n, i, 0);
	}

	const int src = 0;

	for(int i = 0; i < 2 * n; ++i) {
		dist[i] = LL_INF;
	}

	dist[src] = 0;
	set<pair<ll, int>> setik;

	for(int i = 0; i < 2 * n; ++i) {
		setik.emplace(dist[i], i);
	}

	while(!setik.empty()) {
		auto fst = setik.begin();
		int v = fst->second;
		setik.erase(fst);

		for(auto& ed: g[v]) {
			ll weight = ed.second;
			int u = ed.first;

			if(dist[u] > dist[v] + weight) {
				setik.erase({dist[u], u});
				dist[u] = dist[v] + weight;
				setik.emplace(dist[u], u);
			}
		}
	}

	for(int i = 0; i < n; ++i) {
		cout << dist[i] << ' ';
	}

	cout << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}