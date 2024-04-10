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
int B;

int n, m, q;
vi g[N];
int fa[N], cnt[N];
vi has[N];

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int vis[N];
int dp[N], f[N], Max[N];

void dfs(int u, int p) {
	vis[u] = 1;
	for (int i = 0; i < sz(g[u]); i++) {
		int v = g[u][i];
		if (v == p) continue;
		dfs(v, u);
		dp[u] = max(dp[u], dp[v] + 1);
	}
}

void go(int u, int p, int mx) {
	vi pr, sf, to;
	to.pb(0); pr.pb(0); sf.pb(0);
	f[u] = max(mx, dp[u]);
	for (int i = 0; i < sz(g[u]); i++) {
		int v = g[u][i];
		if (v == p) continue;
		to.pb(v); pr.pb(0); sf.pb(0);
	}
	to.pb(0); pr.pb(0); sf.pb(0);
	for (int i = 1; i < sz(to) - 1; i++) pr[i] = max(pr[i - 1], dp[to[i]] + 1);
	for (int i = sz(to) - 2; i >= 1; i--) sf[i] = max(sf[i + 1], dp[to[i]] + 1);
	for (int i = 1; i < sz(to) - 1; i++) {
		int v = to[i];
		go(v, u, max(mx, max(pr[i - 1], sf[i + 1])) + 1);
	}
}

map<pii, double> ans;
vector<ll> sum[N];
vi x[N];

int main() {
	scanf("%d%d%d", &n, &m, &q);
	B = sqrt(n);
	for (int i = 1; i <= n; i++) fa[i] = i, cnt[i] = 1;
	int u, v;
	while (m--) {
		scanf("%d%d", &u, &v);
		g[u].pb(v); g[v].pb(u);
		u = find(u); v = find(v);
		if (u != v) {
			fa[u] = v;
			cnt[v] += cnt[u];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		dfs(i, i);
		go(i, i, 0);
	}
	for (int i = 1; i <= n; i++) {
		has[find(i)].pb(i);
		Max[find(i)] = max(Max[find(i)], f[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (find(i) != i) continue;
		if (cnt[i] >= B) {
			for (int j = 0; j <= n; j++) sum[i].pb(0), x[i].pb(0);
			for (int j = 0;j < sz(has[i]); j++) {
				sum[i][f[has[i][j]]] += f[has[i][j]];
				x[i][f[has[i][j]]]++;
			}
			for (int j = n - 1; j >= 0; j--) sum[i][j] += sum[i][j + 1], x[i][j] += x[i][j + 1];
		}
	}
	while (q--) {
		scanf("%d%d", &u, &v);
		u = find(u), v = find(v);
		if (u == v) printf("-1\n");
		else {
			if (cnt[u] > cnt[v]) swap(u, v);
			if (!ans.count(mp(u, v))) {
				ll tot = 0;
				int dt = max(Max[u], Max[v]);
				if (cnt[v] < B) {
					for (int i = 0; i < sz(has[u]); i++)
						for (int j = 0; j < sz(has[v]); j++)
							tot += max(dt, f[has[u][i]] + f[has[v][j]] + 1);
					ans[mp(u, v)] = 1.0 * tot / sz(has[u]) / sz(has[v]);

				} else {
					for (int i = 0; i < sz(has[u]); i++) {
						int j = max(0, dt - (f[has[u][i]] + 1));
						tot += sum[v][j] + 1ll * x[v][j] * (f[has[u][i]] + 1) + 1ll * (sz(has[v]) - x[v][j]) * dt;
					}
					ans[mp(u, v)] = 1.0 * tot / sz(has[u]) / sz(has[v]);
				}
			}
			printf("%.12f\n", ans[mp(u, v)]);
		}
	}
	return 0;
}