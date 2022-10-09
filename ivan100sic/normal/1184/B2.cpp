#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
struct matching {
	vector<string> a;
	vector<int> u, v;
	int n, m;
 
	matching(int _n, int _m) {
		n = _n;
		m = _m;
		a.assign(n, string(m, 0));
		u.assign(n, -1);
		v.assign(m, -1);
	}
 
	string vis;
 
	bool dfs(int x) {
		vis[x] = true;
		for (int y=0; y<m; y++) {
			if (!a[x][y])
				continue;
			if (v[y] == -1) {
				u[x] = y;
				v[y] = x;
				return true;
			} else if (!vis[v[y]]) {
				if (dfs(v[y])) {
					u[x] = y;
					v[y] = x;
					return true;
				}
			}
		}
		return false;
	}
 
	bool improve() {
		vis = string(n, 0);
		for (int i=0; i<n; i++) {
			if (u[i] == -1 && !vis[i]) {
				if (dfs(i)) {
					return true;
				}
			}
		}
		return false;
	}
};
 
int n, m;
int d[105][105];
 
struct brod {
	int x, a, f;
} a[1005];
 
struct baza {
	int x, d;
} c[1005];
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
 
	cin >> n >> m;
	memset(d, 63, sizeof(d));
	for (int i=0; i<n; i++)
		d[i][i] = 0;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		if (u == v)
			continue;
		d[u][v] = 1;
		d[v][u] = 1;
	}
 
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			for (int k=0; k<n; k++)
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
 
	int s, b, k, h;
	cin >> s >> b >> k >> h;
	for (int i=0; i<s; i++) {
		cin >> a[i].x >> a[i].a >> a[i].f;
		a[i].x--;
	}
	for (int i=0; i<b; i++) {
		cin >> c[i].x >> c[i].d;
		c[i].x--;
	}
 
	matching mecing(s, b);
 
	for (int i=0; i<s; i++) {
		for (int j=0; j<b; j++) {
			mecing.a[i][j] = d[a[i].x][c[j].x] <= a[i].f && a[i].a >= c[j].d;
		}
	}
 
 
	int ms = 0;
	while (mecing.improve())
		ms++;
 
	ll sol = 1e18;
	for (int e=0; e<=s; e++)
		sol = min(sol, 1ll*min(ms, s-e)*k + 1ll*e*h);
	cout << sol << '\n';
}