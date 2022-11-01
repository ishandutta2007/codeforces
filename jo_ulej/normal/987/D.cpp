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
	#define DBG(X) cout << #X << "=" << (X) << endl;
#else
	#define DBG(X)
	#define endl '\n'
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
template<typename T> inline void goodbye(const T& val) { cout << val << endl; exit(0); }

const int MAXN = (int)1e5 + 777;
const int MAXM = (int)1e5 + 777;
const int MAXK = 107;

vector<int> g[MAXN];
int n, m, k, s;
int a[MAXN];

int Q[MAXN], head = 0;
int dist[MAXK][MAXN];
int cur[MAXK];

void solve() {
	cin >> n >> m >> k >> s;

	for(int v = 0; v < n; ++v) {
		cin >> a[v];
		--a[v];
	}

	for(int i = 0; i < m; ++i) {
		int v, u;
		cin >> v >> u;
		--v, --u;

		g[v].push_back(u);
		g[u].push_back(v);
	}

	for(int c = 0; c < k; ++c) {
		head = 0;

		for(int v = 0; v < n; ++v) {
			if(a[v] == c) {
				Q[head++] = v;
				dist[c][v] = 0;
			} else {
				dist[c][v] = INT_INF;
			}
		}

		for(int j = 0; j < head; ++j) {
			int v = Q[j];

			for(auto& u: g[v]) {
				if(dist[c][u] > dist[c][v] + 1) {
					dist[c][u] = dist[c][v] + 1;
					Q[head++] = u;
				}
			}
		}
	}

	for(int v = 0; v < n; ++v) {
		for(int c = 0; c < k; ++c) {
			cur[c] = dist[c][v];
		}

		sort(cur, cur + k);
		ll answ = 0;

		for(int i = 0; i < s; ++i) {
			answ += cur[i];
		}

		cout << answ << ' ';
	}

	cout << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}