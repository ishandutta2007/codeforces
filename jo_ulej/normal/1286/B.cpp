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

const int MAXN = 2000 + 7;
const ll  K    = 3456;
vector<int> tree[MAXN];
int n;
int c[MAXN];
int mark[MAXN];

void fail() {
	cout << "NO\n";
	exit(0);
}

vector<pii> calc(int v) {
	DBG(v);
	vector<pii> subtree;
	for(auto& u: tree[v]) {
		auto s = calc(u);
		for(auto& el: s) subtree.push_back(el);
	}

	sort(subtree.begin(), subtree.end());
	if(c[v] < 0 || c[v] > len(subtree)) fail();

	if(c[v] == 0) {
		if(!subtree.empty()) {
			mark[v] = subtree.front().first - 1; 
		}
	} else if(c[v] == len(subtree)) {
		mark[v] = subtree.back().first + 1;
	} else {
		for(int i = 0; i < len(subtree); ++i) {
			int v = subtree[i].second;
			mark[v] = subtree[i].first = 10 * (i + 1);
		}

		mark[v] = subtree[c[v] - 1].first + 1;
	}

	subtree.emplace_back(mark[v], v);
	return subtree;
}

void solve() {
	cin >> n;
	int root = NIL;
	for(int i = 0; i < n; ++i) {
		int p = fetch<int>() - 1;
		c[i]  = fetch<int>();

		if(p == NIL) {
			root = i;
		} else {
			tree[p].push_back(i);
		}
	}

	assert(root != NIL);
	vector<int> leaves;
	for(int i = 0; i < n; ++i) if(tree[i].empty()) leaves.push_back(i);
	for(int i = 0; i < len(leaves); ++i) mark[leaves[i]] = 10 * (i + 1);
	calc(root);

	vector<int> ord(n, NIL);
	for(int i = 0; i < n; ++i) ord[i] = mark[i];
	sort(ord.begin(), ord.end());
	for(int i = 0; i < n; ++i) mark[i] = lower_bound(ord.begin(), ord.end(), mark[i]) - ord.begin();
	for(int i = 0; i < n; ++i) ++mark[i];

	cout << "YES\n";
	for(int i = 0; i < n; ++i) cout << mark[i] << ' ';
	cout << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}