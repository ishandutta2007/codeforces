#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
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

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;

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

const int N = 1e6 + 7;

int tin[N], tout[N], d[N], ans[N];
vector<int> g[N];
int dp[N][2];
int id[N];
vector<pair<int, int>> leaf;
int k;
int tm = 0;

bool upper(int a, int b) {
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}

void calcleaf(int v){
	tin[v] = tm++;
	if (g[v].empty() && v != 0) {
		id[v] = v;
	}
	else {
		id[v] = -1;
	}
	if (v == 0) d[v] = 0;
	for (int u : g[v]) {
		d[u] = d[v] + 1;
		calcleaf(u);
		if (id[v] == -1 || d[id[v]] > d[id[u]])
			id[v] = id[u];
	}
	tout[v] = tm++;
}

void dfs(int v) {
	dp[v][0] = dp[v][1] = 0;
	//cout << v + 1 << " " << id[v] << endl;
	for (int u : g[v]) {
		dfs(u);
		if (d[id[u]] - d[v] <= k) {
			dp[v][0] += dp[u][0];
		}
	}
	if (g[v].empty() && v != 0) dp[v][0] = 1;
	dp[v][1] = dp[v][0];
	for (int u : g[v]) {
		int t = dp[v][0];
		if (d[id[u]] - d[v] <= k) t -= dp[u][0];
		t += dp[u][1];
		dp[v][1] = max(dp[v][1], t);
	}
}

// 2 16	21

void solve() {
	int n; cin >> n >> k;
	fill(ans, ans + n, 0);
	for (int i = 1; i < n; i++) {
		int t; cin >> t; t--;
		g[t].push_back(i);
	}
	calcleaf(0);
	//for (auto u : leaf) cout << u.first << " " << u.second + 1 << endl;
	dfs(0);
	cout << dp[0][1] << endl;
}