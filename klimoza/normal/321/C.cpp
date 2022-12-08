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

void dfs(int v, int last = -1) {
	d[v] = 1;
	for (int u : g[v]) {
		if (used[u] || u == last) continue;
		dfs(u, v);
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
	dfs(v);
	int c = get_centroid(v, d[v]);
	//cout << c << " " << lst << " " << d[v] << endl;
	if (lst != -1) cd[lst].push_back(c);
	used[c] = true;
	for (int u : g[c]) {
		if (!used[u])
			build(u, c);
	}
	return c;
}

char ans[N];

void makeans(int v, char c = 'A', int last = -1) {
	ans[v] = c;
	for (int u : cd[v]) {
		if (u == last) continue;
		makeans(u, c + 1, v);
	}
}

void solve() {
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int x = build(0);
	makeans(x);
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	return;
}