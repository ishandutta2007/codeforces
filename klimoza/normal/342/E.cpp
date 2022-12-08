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

mt19937 mrand(43);

const double PI = acos((double)-1);
const double eps = 1e-5;
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

vector<int> g[N];

vector<int> cd[N];

bool used[N];

int d[N];

int p[N];

void buildsz(int v, int last = -1) {
	d[v] = 1;
	for (int u : g[v]) {
		if (used[u] || u == last) continue;
		buildsz(u, v);
		d[v] += d[u];
	}
}

int get_centroid(int v, int sz, int last = -1) {
	for (int u : g[v]) {
		if (used[u] || u == last) continue;
		if (2 * d[u] > sz) return get_centroid(u, sz, v);
	}
	return v;
}

int build(int v, int lst = -1) {
	buildsz(v);
	int c = get_centroid(v, d[v]);
	//cout << c << " " << lst << " " << d[v] << endl;
	if (lst != -1) {
		p[c] = lst;
		cd[lst].push_back(c);
	}
	used[c] = true;
	for (int u : g[c]) {
		if (!used[u])
			build(u, c);
	}
	return c;
}

const int L = 20;

int up[N][L];
int tin[N], tout[N];

int timer = 0;

void dfs(int v, int last = -1) {
	tin[v] = timer++;
	if (last == -1) d[v] = 0;
	else d[v] = d[last] + 1;
	if (last == -1) up[v][0] = v;
	else up[v][0] = last;
	for (int l = 1; l < L; l++)
		up[v][l] = up[up[v][l - 1]][l - 1];
	for (int u : g[v]) {
		if (u == last) continue;
		dfs(u, v);
	}
	tout[v] = timer++;
}

bool upper(int a, int b) {
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b) {
	if (upper(a, b)) return a;
	if (upper(b, a)) return b;
	for (int l = L - 1; l >= 0; l--) {
		if (!upper(up[a][l], b))
			a = up[a][l];
	}
	return up[a][0];
}

int nst[N];

int dist(int a, int b) {
	return d[a] + d[b] - 2 * d[lca(a, b)];
}

void solve() {
	fill(nst, nst + N, 2e9);
	int n; cin >> n;
	int m; cin >> m;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int x = build(0);
	p[x] = -1;
	dfs(0);
	for (int i = 0; i < n; i++)
		nst[i] = d[i];
	while (m--) {
		int t, v; cin >> t >> v; v--;
		if (t == 1) {
			int x = v;
			while (x != -1) {
				nst[x] = min(nst[x], dist(x, v));
				x = p[x];
			}
		}
		else {
			int x = v;
			int ans = 2e9;
			while (x != -1) {
				ans = min(ans, dist(x, v) + nst[x]);
				x = p[x];
			}
			cout << ans << endl;
		}
	}
	return;
}