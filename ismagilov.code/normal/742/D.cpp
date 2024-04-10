#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"

using namespace std;

const int MAXN = 1001;

vector<int> g[MAXN];
bool used[MAXN];
int colored[MAXN];

void dfs(int v, int color) {
	used[v] = 1;
	colored[v] = color;
	for (auto to : g[v]) {
		if (!used[to]) {
			dfs(to, color);
		}
	}
}

main() {
	ios_base::sync_with_stdio(0);
	int n, m, w;
	cin >> n >> m >> w;
	pair<int, int> a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i].fs;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i].sc;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a - 1].pb(b - 1);
		g[b - 1].pb(a - 1);
	}
	int color = 0;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			color++;
			dfs(i, color);
		}
	}
	vector<vc<pair<int, int> > > ans;
	for (int i = 0; i < color + 1; i++) {
		vector<pr<int, int> > tek;
		pr<int, int> ty = mp(0, 0);
		for (int j = 0; j < n; j++) {
			if (colored[j] == i) {
				tek.pb(a[j]);
				ty.fs += a[j].fs;
				ty.sc += a[j].sc;
			}
		}
		tek.pb(ty);
		ans.pb(tek);
	}
	int di[color + 1][w + 1];
	for (int i = 0; i < color + 1; i++) {
		di[i][0] = 0;
	}
	for (int i = 0; i < w + 1; i++) {
		di[0][i] = 0;
	}
	for (int i = 1; i < color + 1; i++) {
		for (int j = 1; j < w + 1; j++) {
			di[i][j] = di[i - 1][j];
			for (auto v : ans[i]) {
				if (v.fs <= j) {
					di[i][j] = max(di[i][j], v.sc + di[i - 1][j - v.fs]);
				}
			}
		}
	}
	int anss = 0;
	for (int i = 0; i < w + 1; i++) {
		anss = max(anss, di[color][i]);
	}
	cout << anss;
}