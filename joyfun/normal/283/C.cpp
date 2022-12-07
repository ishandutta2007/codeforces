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

const int N = 305;
const int mod = 1e9+7;

int n, q, t, a[N], vis[N], w[N], d[N], f[N], u[N], v[N];
vi g[N];
int dp[100005];

void pp(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}
queue<int> Q;

int main() {
	scanf("%d%d%d", &n, &q, &t);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= q; i++) {
		scanf("%d%d", &u[i], &v[i]);
		g[u[i]].pb(v[i]); d[v[i]]++;
	}
	for (int i = 1; i <= n; i++) if (!d[i]) Q.push(i);
	int tot = 0;
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		tot++;
		w[u] += a[u];
		for (int i = 0; i < sz(g[u]); i++) {
			int v = g[u][i];
			d[v]--;
			w[v] += w[u];
			if (!d[v]) Q.push(v);
		}
	}
	if (tot != n) {
		printf("0\n");
		return 0;
	}
	for (int i = 1; i <= n; i++) g[i].clear();
	for (int i = 1; i <= q; i++) g[v[i]].pb(u[i]), d[u[i]]++;
	for (int i = 1; i <= n; i++) if (!d[i]) Q.push(i);
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		for (int i = 0; i < sz(g[u]); i++) {
			int v = g[u][i];
			d[v]--;
			f[v] = max(f[v], f[u] + 1);
			if (!d[v]) Q.push(v);
		}
	}
	for (int i = 1; i <= n; i++) {
		t -= a[i] * f[i];
		if (t < 0) break;
	}
	if (t < 0) {
		printf("0\n");
	} else {
		dp[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = w[i]; j <= t; j++) {
				pp(dp[j], dp[j - w[i]]);
			}
		}
		printf("%d\n", dp[t]);
	}
	return 0;
}