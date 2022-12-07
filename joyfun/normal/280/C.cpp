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
double ans;

void dfs(int u, int p, int h) {
	ans += 1.0 / h;
	for (int i = 0; i < sz(g[u]); i++) {
		int v = g[u][i];
		if (v == p) continue;
		dfs(v, u, h + 1);
	}
}

int main() {
	scanf("%d", &n);
	int u, v;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &u, &v);
		g[u].pb(v); g[v].pb(u);
	}
	dfs(1, 1, 1);
	printf("%f\n", ans);
	return 0;
}