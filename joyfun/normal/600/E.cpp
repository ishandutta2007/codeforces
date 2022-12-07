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
int n, c[N];
vi g[N];
map<int, int> cnt[N];
int Max[N];
ll sum[N], ans[N];

void dfs(int u, int p) {
	cnt[u][c[u]]++, Max[u] = 1, sum[u] = c[u];
	for (int i = 0; i < sz(g[u]); i++) {
		int v = g[u][i];
		if (v == p) continue;
		dfs(v, u);
		if (sz(cnt[u]) < sz(cnt[v])) {
			swap(cnt[u], cnt[v]);
			swap(Max[u], Max[v]);
			swap(sum[u], sum[v]);
		}
		for (map<int, int>::iterator it = cnt[v].begin(); it != cnt[v].end(); it++) {
			cnt[u][it->fi] += it->se;
			if (cnt[u][it->fi] > Max[u]) {
				Max[u] = cnt[u][it->fi];
				sum[u] = it->fi;
			} else if (cnt[u][it->fi] == Max[u])
				sum[u] += it->fi;
		}
	}
	ans[u] = sum[u];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	int u, v;
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		g[u].pb(v); g[v].pb(u);
	}
	dfs(1, 1);
	for (int i = 1; i <= n; i++) printf("%lld ", ans[i]); printf("\n");
	return 0;
}