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

const int MAXN = (int)3e5 + 777;
int a[MAXN], n;
int p[MAXN], H[MAXN];
ll dp[MAXN], answ;

struct Node {
	int val = NIL, left = NIL, right = NIL;
};

vector<Node> tree;

int alloc() {
	tree.emplace_back();
	return len(tree) - 1;
}

int change(int v, int tl, int tr, int pos, int val) {
	if(pos < tl || pos > tr) {
		return v;
	}

	int u = alloc();

	if(tl == tr) {
		tree[u].val = val;
	} else {
		int tm = (tl + tr) / 2;
		tree[u].left = (v == NIL ? NIL : tree[v].left);
		tree[u].right = (v == NIL ? NIL : tree[v].right);

		if(pos <= tm) {
			tree[u].left = change(tree[u].left, tl, tm, pos, val);
		} else {
			tree[u].right = change(tree[u].right, tm + 1, tr, pos, val);
		}
	}

	return u;
}

int get(int v, int tl, int tr, int pos) {
	while(tl != tr && v != NIL) {
		int tm = (tl + tr) / 2;

		if(pos <= tm) {
			v = tree[v].left;
			tr = tm;
		} else {
			v = tree[v].right;
			tl = tm + 1;
		}
	}

	return (v == NIL ? NIL : tree[v].val);
}

void test_tree() {
	SAY("BEGIN TEST");
	int rt = NIL;
	rt = change(rt, 0, 100, 13, 13);
	DBG(get(rt, 0, 100, 13));
	DBG(get(rt, 0, 100, 29));

	SAY("END TEST");
}

void solve() {
	cin >> n;

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for(int i = 0; i <= n; ++i) {
		H[i] = NIL;
	}

	/*for(int i = n - 1; i >= 0; --i) {
		int j = i + 1;

		while(j != NIL && j < n && a[j] != a[i]) {
			j = p[j];
		}

		p[i] = (j != NIL && a[j] == a[i] ? j + 1 : NIL);
	}*/

	for(int i = n - 1; i >= 0; --i) {
		int j = get(H[i + 1], 0, n, a[i]);
		p[i] = (j == NIL ? NIL : j + 1);

		H[i] = change(p[i] == NIL ? NIL : H[p[i]], 0, n, a[i], i);
	}

#ifdef __LOCAL
	for(int i = 0; i < n; ++i) {
		cout << p[i] << ' ';
	}

	cout << '\n';
#endif

	answ = 0;
	dp[n] = 0;
	for(int i = n - 1; i >= 0; --i) {
		dp[i] = 0;

		if(p[i] != NIL) {
			++dp[i];
			dp[i] += dp[p[i]];
		}

		answ += dp[i];
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