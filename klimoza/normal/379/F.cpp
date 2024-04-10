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
typedef complex<double> cd;
typedef vector<complex<double>> vcd;

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

const int L = 21;
const int N = 1e6 + 7;

vector<int> g[N];

int up[N][L];
int d[N];

void dfs(int v, int last = -1) {
	if (last == -1) up[v][0] = v;
	else up[v][0] = last;
	for (int l = 1; l < L; l++)
		up[v][l] = up[up[v][l - 1]][l - 1];
	for (int u : g[v]) {
		if (u == last) continue;
		d[u] = d[v] + 1;
		dfs(u, v);
	}
}

int upp(int a, int d) {
	for (int l = L - 1; l >= 0; l--) {
		if ((1 << l) & d)
			a = up[a][l];
	}
	return a;
}

int lca(int a, int b) {
	if (d[a] < d[b]) swap(a, b);
	a = upp(a, d[a] - d[b]);
	for (int l = L - 1; l >= 0; l--) {
		if (up[a][l] != up[b][l]) {
			a = up[a][l];
			b = up[b][l];
		}
	}
	return up[a][0];
}

void solve() {
	d[0] = 0;
	g[0] = { 1, 2, 3 };
	int x = 1;
	int ans = 2;
	dfs(0);
	int q; cin >> q;
	int n = 4;
	while (q--) {
		int v; cin >> v; v--;
		d[n] = d[n + 1] = d[v] + 1;
		up[n][0] = up[n + 1][0] = v;
		for (int l = 1; l < L; l++) {
			up[n][l] = up[up[n][l - 1]][l - 1];
			up[n + 1][l] = up[up[n + 1][l - 1]][l - 1];
		}
		if (d[x] == d[v]) {
			ans++;
			x = n;
		}
		else {
			int t = lca(n, x);
			ans = max(ans, d[n] + d[x] - 2 * d[t]);
		}
		n += 2;
		cout << ans << endl;
	}
	return;
}