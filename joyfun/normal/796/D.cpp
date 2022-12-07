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
int n, k, d, dp[N], p[N];
queue<int> Q;
vector<pii> g[N];
vi ans;

int main() {
	scanf("%d%d%d", &n, &k, &d);
	memset(dp, -1, sizeof(dp));
	while (k--) {
		int x;
		scanf("%d", &x);
		if (dp[x] != -1) continue;
		dp[x] = 0;
		Q.push(x);
	}
	for (int i = 1; i <= n - 1; i++) {
		int u, v; scanf("%d%d", &u, &v);
		g[u].pb(mp(v, i)); g[v].pb(mp(u, i));
	}
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		for (int i = 0; i < sz(g[u]); i++) {
			int v = g[u][i].fi;
			int id = g[u][i].se;
			if (v == p[u]) continue;
			if (dp[v] != -1) ans.pb(id);
			else {
				if (dp[u] + 1 <= d) {
					dp[v] = dp[u] + 1;
					p[v] = u;
					Q.push(v);
				}
			}	
		}
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	printf("%d\n", sz(ans));
	for (int i = 0; i < sz(ans); i++) printf("%d ", ans[i]); printf("\n");
	return 0;
}