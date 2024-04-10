#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010, dx[] = {0, 0, 0, 1, 2, 2, 2, 1}, dy[] = {0, 1, 2, 2, 2, 1, 0, 0};
int n, m; char a[maxn][maxn]; bool vis[maxn][maxn];

inline void work(const int& x, const int& y) {
	if (n - x < 2 || m - y < 2) return;
	bool flag = 1;
	for (int i = 0; i < 8 && flag; i++) {
		if (a[x + dx[i]][y + dy[i]] != '#') { flag = 0; break; }
	}
	if (!flag) return;
	for (int i = 0; i < 8; i++) {
		vis[x + dx[i]][y + dy[i]] = 1;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", a[i] + 1);
	}
	for (register int i = 1; i <= n; i++) {
		for (register int j = 1; j <= m; j++) {
			work(i, j);
		}
	}
	bool flag = 1;
	for (register int i = 1; i <= n && flag; i++) {
		for (register int j = 1; j <= m && flag; j++) {
			if (a[i][j] == '#') flag &= vis[i][j];
		}
	}
	puts(flag ? "YES" : "NO");
	return 0;
}