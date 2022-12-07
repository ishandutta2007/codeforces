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

vi g[N];
pii w[N];
int ans[N];

void dfs(int u, int c) {
	if (ans[u] != -1) return;
	ans[u] = c;
	for (int i = 0; i < sz(g[u]); i++) {
		int v = g[u][i];
		dfs(v, c^1);
	}
}

int main() {
	int l, r;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &l, &r);
		r++;
		g[i * 2 - 1].pb(i * 2); g[i * 2].pb(i * 2 - 1);
		w[i * 2 - 1] = mp(l, i * 2 - 1); w[i * 2] = mp(r, i * 2);
	}
	n *= 2;
	sort(w + 1, w + 1 + n);
	for (int i = 1; i < n; i += 2) {
		g[w[i].se].pb(w[i + 1].se);
		g[w[i + 1].se].pb(w[i].se);
	}
	memset(ans, -1, sizeof(ans));
	for (int i = 1; i <= n; i++)
		dfs(i, 0);
	for (int i = 1; i <= n; i += 2) printf("%d ", ans[i]);
	return 0;
}