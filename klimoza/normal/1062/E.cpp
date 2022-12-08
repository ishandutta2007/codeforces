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
//const ll mod = 1e9 + 7;
const ll mod = 998244353;

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

struct T {
	vector<pair<int, int>> tmax;
	vector<pair<int, int>> tmin;
	vector<pair<int, int>> a;
	T() {}
	T(vector<pair<int, int>> a) : a(a) {
		tmin.resize(4 * a.size());
		tmax.resize(4 * a.size());
		build(0, 0, a.size());
	}
	void build(int v, int l, int r) {
		if (r - l == 1) {
			tmax[v] = a[l];
			tmin[v] = a[l];
			return;
		}
		build(2 * v + 1, l, (l + r) / 2);
		build(2 * v + 2, (l + r) / 2, r);
		tmax[v] = max(tmax[2 * v + 1], tmax[2 * v + 2]);
		tmin[v] = min(tmin[2 * v + 1], tmin[2 * v + 2]);
	}
	pair<int, int> getmax(int v, int l, int r, int vl, int vr) {
		if (l >= vr || vl >= r) return { -1, -1 };
		if (vl <= l && r <= vr) return tmax[v];
		return max(getmax(2 * v + 1, l, (l + r) / 2, vl, vr), getmax(2 * v + 2, (l + r) / 2, r, vl, vr));
	}
	pair<int, int> getmin(int v, int l, int r, int vl, int vr) {
		if (l >= vr || vl >= r) return { 2e9, 2e9 };
		if (vl <= l && r <= vr) return tmin[v];
		return min(getmin(2 * v + 1, l, (l + r) / 2, vl, vr), getmin(2 * v + 2, (l + r) / 2, r, vl, vr));
	}
};

const int N = 1e5 + 7;
const int L = 20;

vector<int> g[N];

int tin[N], tout[N], p[N][L], d[N];
int tim = 0;

void dfs(int v, int last = -1) {
	tin[v] = tim++;
	if (last == -1) d[v] = 0;
	if (last == -1) p[v][0] = v;
	else p[v][0] = last;
	for (int l = 1; l < L; l++) {
		p[v][l] = p[p[v][l - 1]][l - 1];
	}
	for (auto u : g[v]) {
		d[u] = d[v] + 1;
		dfs(u, v);
	}
	tout[v] = tim++;
}

bool upper(int a, int b) {
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b) {
	if (upper(a, b)) return a;
	if (upper(b, a)) return b;
//	if (a == 3) cout << a + 1 << " " << b + 1 << " " << p[a][0] << endl;
	for (int l = L - 1; l >= 0; l--) {
		if (!upper(p[a][l], b)) a = p[a][l];
	}
	return p[a][0];
}

void solve() {
	int n, q; cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int t; cin >> t; t--;
		g[t].push_back(i);
	}
	dfs(0);
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = { tin[i], i };
	}
	T t = T(a);
	while (q--) {
		int a, b; cin >> a >> b; a--; b--;
		int u = t.getmin(0, 0, n, a, b + 1).second;
		int v = t.getmax(0, 0, n, a, b + 1).second;
	//	cout << u + 1 << " " << v + 1 << endl;
	//	cout << lca(u, v) + 1 << endl;
		int l1 = b, l2 = b;
		if (u != a) l1 = lca(t.getmin(0, 0, n, a, u).second, t.getmax(0, 0, n, a, u).second);
		if (u != b) l1 = lca(l1, lca(t.getmin(0, 0, n, u + 1, b + 1).second, t.getmax(0, 0, n, u + 1, b + 1).second));
	//	cout << l1 + 1 << endl;
		if (v != a) l2 = lca(t.getmin(0, 0, n, a, v).second, t.getmax(0, 0, n, a, v).second);
		if (v != b) l2 = lca(l2, lca(t.getmin(0, 0, n, v + 1, b + 1).second, t.getmax(0, 0, n, v + 1, b + 1).second));
	//	cout << l2 + 1 << endl;
		if (d[l1] > d[l2]) cout << u + 1 << " " << d[l1] << endl;
		else cout << v + 1 << " " << d[l2] << endl;
	}
}