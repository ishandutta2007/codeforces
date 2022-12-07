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

const int N = 200005;
int n, m, k;
vi g[N];
vector<vi> ans;
vi tmp;
int vis[N];

void dfs(int u) {
	vis[u] = 1;
	tmp.pb(u);
	if (sz(tmp) == (2 * n + k - 1) / k) {
		ans.pb(tmp);
		tmp.clear();
	}
	int f = 1;
	for (int i = 0; i < sz(g[u]); i++) {
		int v = g[u][i];
		if (vis[v]) continue;
		f = 0;
		dfs(v);
		tmp.pb(u);
		if (sz(tmp) == (2 * n + k - 1) / k) {
			ans.pb(tmp);
			tmp.clear();
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	int u, v;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &u, &v);
		g[u].pb(v); g[v].pb(u);
	}
	dfs(1);
	if (sz(tmp)) {
		ans.pb(tmp);
		tmp.clear();
	}
	while (sz(ans) < k) {
		tmp.pb(1);
		for (int i = sz(ans) + 1; i <= k; i++)
			ans.pb(tmp);
	}
	for (int i = 0; i < sz(ans); i++) {
		printf("%d", sz(ans[i]));
		for (int j = 0; j < sz(ans[i]); j++)
			printf(" %d", ans[i][j]);
		printf("\n");
	}
	return 0;
}