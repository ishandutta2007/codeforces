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

const int MAXN = (int)1007;
vector<int> g[MAXN];
int n, m, s[2];
int dist[2][MAXN];
int Q[MAXN], head = 0;
bitset<MAXN> h[MAXN];

void solve() {
	cin >> n >> m;
	s[0] = fetch<int>() - 1;
	s[1] = fetch<int>() - 1;

	for(int i = 0; i < m; ++i) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;

		g[v].push_back(u);
		g[u].push_back(v);

		h[v][u] = h[u][v] = 1;
	}

	for(int t = 0; t < 2; ++t) {
		head = 0;
		Q[head++] = s[t];

		for(int i = 0; i < n; ++i) {
			dist[t][i] = (s[t] == i ? 0 : INT_INF);
		}

		for(int j = 0; j < head; ++j) {
			int v = Q[j];
			for(auto& u: g[v]) {
				if(dist[t][u] > dist[t][v] + 1) {
					dist[t][u] = dist[t][v] + 1;
					Q[head++] = u;
				}
			}
		}
	}

	int fdist = dist[0][s[1]];
	int answ = 0;
	for(int v = 0; v < n; ++v) {
		for(int u = 0; u < v; ++u) {
			if(!h[v][u]) {
				int local = min(dist[0][v] + dist[1][u], dist[0][u] + dist[1][v]) + 1;
				if(local >= fdist) {
					++answ;
				}
			}
		}
	}

	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}