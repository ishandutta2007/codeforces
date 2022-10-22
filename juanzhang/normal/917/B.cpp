#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n, m, e[maxn][maxn], f[maxn][maxn][27];

bool dfs(int x, int y, int lst) {
	int& res = f[x][y][lst];
	if (~res) return res;
	res = 0;
	for (int i = 1; i <= n; i++) {
		if (e[x][i] >= lst && !dfs(y, i, e[x][i])) {
			return res = 1;
		}
	}
	return 0;
}

int main() {
	scanf("%d %d", &n, &m);
	memset(e, -1, sizeof e);
	memset(f, -1, sizeof f);
	for (int i = 1; i <= m; i++) {
		int u, v; char str[5];
		scanf("%d %d %s", &u, &v, str);
		e[u][v] = *str - 'a';
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			putchar('B' - dfs(i, j, 0));
		}
		putchar(10);
	}
	return 0;
}