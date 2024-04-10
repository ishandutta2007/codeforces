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
int n;
vi g[N];
int a[N], b[N];
vi ans;

void dfs(int u, int p, int x, int y, int d) {
	if (d % 2 == 0) {
		if (a[u]^x != b[u]) {
			x ^= 1;
			ans.pb(u);
		}
	} else {
		if (a[u]^y != b[u]) {
			y ^= 1;
			ans.pb(u);
		}
	}
	for (int i = 0; i < sz(g[u]); i++) {
		int v = g[u][i];
		if (v == p) continue;
		dfs(v, u, x, y, d + 1);
	}
}

int main() {
	scanf("%d", &n);
	int u, v;
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	dfs(1, 1, 0, 0, 0);
	printf("%d\n", sz(ans));
	for (int i = 0; i < sz(ans); i++)
		printf("%d\n", ans[i]);
	return 0;
}