/*#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC target("avx2")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
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

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-7;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
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

const int N = 1e5 + 7;	

int d[N][2];

vector<int> g[N];

int ans = 0;

int max(int a, int b, int c) {
	return max(max(a, b), c);
}

void dfs(int v, int last = -1) {
	int m0 = 0;
	int m1 = 0;
	for (int u : g[v]) {
		if (u == last) continue;
		dfs(u, v);
		ans = max(ans, d[u][1] + 1 + m1);
		int kek = max(d[u][0], d[u][1]) + max(m1, m0) + g[v].size();
		int cnt = g[v].size();
		if (last != -1) cnt--;
		kek -= min(cnt, 2);
		ans = max(ans, kek);
		m0 = max(m0, d[u][0]);
		m1 = max(m1, d[u][1]);
	}
	d[v][0] = m1 + 1;
	if (g[v].size() != 1 || last == -1)
		d[v][1] = max(m1, m0) + (g[v].size() - 1) - (last == -1 ? 0 : 1);
	else
		d[v][1] = 0;
	ans = max(ans, max(d[v][0], d[v][1]));
	//cout << v + 1 << " " << d[v][0] << " " << d[v][1] <<  endl;
}

void solve() {
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	cout << ans << endl;
	return;
}