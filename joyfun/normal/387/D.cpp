#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define INF 0x3f3f3f3f
const int N = 505;

int n, m, g[N][N], ind[N], out[N], match[N], vis[N];

bool find(int u, int i) {
	for (int j = 1; j <= n; j++) {
		if (u == j || vis[j] || !g[i][j]) continue;
		vis[j] = 1;
		if (match[j] == -1 || find(u, match[j])) {
			match[j] = i;
			return true;
		}
	}
	return false;
}

int cal(int u) {
	int ans = 0;
	memset(match, -1, sizeof(match));
	for (int i = 1; i <= n; i++) {
		if (i == u) continue;
		memset(vis, 0, sizeof(vis));
		if (find(u, i)) ans++;
	}
	return ans;
}

int solve(int u) {
	int uedge = ind[u] + out[u] - g[u][u];//u
	int ans = 2 * n - 1 - uedge;
	int Max = cal(u);
	ans += m - uedge - Max; //
	ans += n - 1 - Max; //
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	int x, y, ans = INF, mm = m;
	while (mm--) {
		scanf("%d%d", &x, &y);
		g[x][y] = 1;
		ind[y]++;
		out[x]++;
	}
	for (int i = 1; i <= n; i++) {
		int t = solve(i);
		ans = min(ans, t);
	}
	printf("%d\n", ans);
	return 0;
}