//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
//#pragma GCC target("avx2")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <deque>
#include <bitset>
#include <string>
#include <queue>
#include <complex>
#include <stack>
#include <ctime>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double PI = acos((double)-1);
const double eps = 1e-5;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

void solve();
void scan();

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

const int N = 2e5 + 2;

vector<int> g[N];

ll a[N], c[N], sz[N];

ll m;

void build(int v) {
	c[v] += a[v];
	for (int u : g[v]) {
		build(u);
		sz[v] += sz[u];
		c[v] += c[u];
	}
	if (g[v].empty())
		sz[v]++;
}

bool dfs(int v) {
	for (int u : g[v]) {
		if (!dfs(u))
			return false;
	}
	if ((!m && !c[v]) || (m && sz[v] >= (c[v] + m - 1) / m)) return true;
	return false;
}

void solve() {
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int x; cin >> x; x--;
		g[x].push_back(i);
	}
	fill(c, c + N, 0);
	fill(sz, sz + N, 0);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	build(0);
	ll l = -1, r = n * 1e9;
	while (r - l > 1) {
		m = l + r >> 1;
		if (dfs(0))
			r = m;
		else
			l = m;
	}
	cout << r << endl;
	return;
}