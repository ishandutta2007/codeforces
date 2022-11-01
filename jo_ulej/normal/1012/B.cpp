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
template<typename T> inline void goodbye(const T& val) { cout << val << endl; exit(0); }

const int MAXN = (int)4e5 + 777;
int n, m, q;
int parent[MAXN], cnt[MAXN];

void init_DSU() {
	for(int i = 0; i < MAXN; ++i) {
		parent[i] = i;
		cnt[i] = 1;
	}
}

int get_parent(int v) {
	return (v == parent[v] ? v : parent[v] = get_parent(parent[v]));
}

int connect(int v, int u) {
	v = get_parent(v);
	u = get_parent(u);

	if(v != u) {
		if(cnt[v] > cnt[u]) {
			swap(v, u);
		}

		parent[v] = u;
		cnt[u] += cnt[v];

		return 1;
	} else {
		return 0;
	}
}

void solve() {
	cin >> n >> m >> q;
	int answ = n + m - 1;

	while(q--) {
		int v = fetch<int>() - 1;
		int u = n + fetch<int>() - 1;

		answ -= connect(v, u);
	}

	cout << answ << '\n';
}

int main() {
	fast_io();

	init_DSU();
	solve();

	return 0;
}