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
#define endd ; exit(0)

using namespace std;

const int MAXN = 1e5;
const int INF = 1e9;
const int MOD = 1e9 + 7;

vc<pr<int, int>> dd;

vc<pr<int, int> > g[MAXN];
bool used[MAXN];

void kon() {
	cout << -1;
	exit(0);
}

void dfs(int v, int m) {
	sort(g[v].begin(), g[v].end());
	reverse(g[v].begin(), g[v].end());
	used[v] = 1;
	for (int i = 0; i < m; i++) {
		bool prav = 0;
		for (int j = i; j < len(g[v]) && !prav; j++) {
			auto to = g[v][j];
			if (!used[to.sc]) {
				dd.pb(mp(v, to.sc));
				dfs(to.sc, to.fs);
				prav = 1;
			}
		}
	}
}

main() {
	//freopen("kek.in", "r", stdin);
	//freopen("kek.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				g[i].pb(mp(a[j], j));
			}
		}
	}
	dfs(0, a[0]);
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			kon();
		}
	}
	cout << len(dd) << endl;
	for (auto v : dd) {
		cout << v.fs + 1 << ' ' << v.sc + 1 << endl;
	}
}