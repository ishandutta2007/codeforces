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

const int N = 100005;
int n, m;
vector<pii> g[N];
int vis[N], vs[N];
vector<pair<pii, int> > ans;

int dfs(int u, int p) {
	vis[u] = 1;
	int pr = -1;
	for (int i = 0; i < sz(g[u]); i++) {
		int v = g[u][i].fi;
		int id = g[u][i].se;
		if (v == p) continue;
		if (vs[id]) continue;
		vs[id] = 1;
		if (vis[v]) {
			if (pr != -1) {
				ans.pb(mp(mp(pr, u), v));
				pr = -1;
			} else pr = v;
		} else {
			int nx = dfs(v, u);
			if (pr == -1) pr = nx;
			else if (pr != -1 && nx != -1) {
				ans.pb(mp(mp(pr, u), nx));
				pr = -1;
			}
		}
	}
	if (pr != -1) {
		ans.pb(mp(mp(p, u), pr));
		pr = -1;
	} else pr = u;
	return pr;
}

int main() {
	scanf("%d%d", &n, &m);
	if (m % 2) {
		printf("No solution\n");
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].pb(mp(v, i)); g[v].pb(mp(u, i));
	}
	dfs(1, 1);
	for (int i = 0; i < sz(ans); i++)
		printf("%d %d %d\n", ans[i].fi.fi, ans[i].fi.se, ans[i].se);
	return 0;
}