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

const int N = 3005;
const int inf = 0x3f3f3f3f;
int n, m;
vi g[N];
int u[N], v[N], d[N][N];
int s[2], t[2], l[2];
queue<int> Q;

void bfs(int s, int *d) {
	Q.push(s);
	for (int i = 1; i <= n; i++) d[i] = -1;
	d[s] = 0;
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		for (int i = 0; i < sz(g[u]); i++) {
			int v = g[u][i];
			if (d[v] != -1) continue;
			d[v] = d[u] + 1;
			Q.push(v);
		}
	}
}

int cal(int u, int v) {
	int ans = d[u][v];
	for (int i = 0; i < 2; i++) {
		if (d[s[i]][u] + d[u][v] + d[v][t[i]] > l[i] && d[s[i]][v] + d[u][v] + d[u][t[i]] > l[i]) return inf;
		ans += min(d[s[i]][v] + d[u][t[i]], d[s[i]][u] + d[v][t[i]]);
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &u[i], &v[i]);
		g[u[i]].pb(v[i]);
		g[v[i]].pb(u[i]);
	}
	for (int i = 1; i <= n; i++) bfs(i, d[i]);
	for (int i = 0; i < 2; i++)
		scanf("%d%d%d", &s[i], &t[i], &l[i]);
	int ans = 0;
	for (int i = 0; i < 2; i++) {
		if (d[s[i]][t[i]] > l[i]) {
			printf("-1\n");
			return 0;
		}
		ans += d[s[i]][t[i]];
	}
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			ans = min(ans, cal(i, j));
	printf("%d\n", m - ans);
	return 0;
}