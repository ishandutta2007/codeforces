#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 300005;
int n, m;
vi g[N];
set<int> s[N];
int ans[N];
int Max;

void dfs(int u, int p, set<int> vis) {
	int c = 1;
	for (set<int>::iterator it = s[u].begin(); it != s[u].end(); it++) {
		if (ans[*it] != 0) continue;
		while (vis.find(c) != vis.end()) c++;
		ans[*it] = c++;
	}
	for (int i = 0; i < sz(g[u]); i++) {
		int v = g[u][i];
		if (v == p) continue;
		set<int> vis;
		for (set<int>::iterator it = s[v].begin(); it != s[v].end(); it++)
			if (s[u].find(*it) != s[u].end()) vis.insert(ans[*it]);
		dfs(v, u, vis);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int k, x; scanf("%d", &k);
		while (k--) {
			scanf("%d", &x);
			s[i].insert(x);
		}
	}
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		g[u].pb(v); g[v].pb(u);
	}
	set<int> tmp;
	dfs(1, 1, tmp);
	for (int i = 1; i <= m; i++) if (!ans[i]) ans[i] = 1;
	for (int i = 1; i <= m; i++) Max = max(Max, ans[i]);
	printf("%d\n", Max);
	for (int i = 1; i <= m; i++) printf("%d ", ans[i]); printf("\n");
	return 0;
}