#include <bits/stdc++.h>
using namespace std;

const int maxn = 7;
bool vis[maxn];
int ans, a[maxn], g[maxn][maxn];

void dfs(int now) {
	if (now > 5) {
		ans = max(ans, g[a[1]][a[2]] + g[a[3]][a[4]] + g[a[2]][a[3]] + g[a[4]][a[5]] + g[a[3]][a[4]] + g[a[4]][a[5]] +
		               g[a[2]][a[1]] + g[a[4]][a[3]] + g[a[3]][a[2]] + g[a[5]][a[4]] + g[a[4]][a[3]] + g[a[5]][a[4]]);
		return;
	}
	for (int i = 1; i < 6; i++) {
		if (!vis[i]) {
			vis[i] = 1, a[now] = i, dfs(now + 1), vis[i] = 0;
		}
	}
}

int main() {
	for (int i = 1; i < 6; i++) {
		for (int j = 1; j < 6; j++) {
			scanf("%d", &g[i][j]);
		}
	}
	dfs(1);
	printf("%d", ans);
	return 0;
}