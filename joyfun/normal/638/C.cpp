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
int n;
vector<pii> g[N];
vi ans[N];
int tot;

void dfs(int u, int p, int c) {
	int s = 0;
	for (int i = 0; i < sz(g[u]); i++) {
		int v = g[u][i].fi;
		if (v == p) continue;
		s++; if (s == c) s++;
		ans[s].pb(g[u][i].se);
		tot = max(tot, s);
		dfs(v, u, s);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].pb(mp(v, i)); g[v].pb(mp(u, i));
	}
	dfs(1, 1, 0);
	printf("%d\n", tot);
	for (int i = 1; i <= tot; i++) {
		printf("%d", sz(ans[i]));
		for (int j = 0; j < sz(ans[i]); j++)
			printf(" %d", ans[i][j]);
		printf("\n");
	}
	return 0;
}