// Hydro submission #61ea4c222d9ea534f2ea81fb@1642744867346
#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x = 0, f = 0; char c = 0;
	while (!isdigit(c)) f |= c == '-', c = getchar();
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
	return f ? -x : x;
}

#define N 1010
#define INF 1000000007

int n, m, s, t, a[N][N], Mn = INF, res = 0, vis[N], d[2][N];

void bfs(int st, int op) {
	for (int i = 1; i <= n; i ++) d[op][i] = INF;
	queue<int> q;
	memset(vis, 0, sizeof vis);
	d[op][st] = 0, vis[st] = 1, q.push(st);

	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int y = 1; y <= n; y ++) {
			if (!a[x][y] || vis[y]) continue;
			d[op][y] = d[op][x] + 1;
			vis[y] = 1, q.push(y);
		}
	}
}

int main() {
	// freopen("test.in", "r", stdin);
	// freopen("test.out", "w", stdout);

	n = read(), m = read(), s = read(), t = read();
	for (int i = 1; i <= m; i ++) {
		int x = read(), y = read();
		a[x][y] = a[y][x] = 1;
	}

	bfs(s, 0), bfs(t, 1);
	for (int i = 1; i <= n; i ++) {
		Mn = min(Mn, d[0][i] + d[1][i]);
	}
	if (Mn == INF) return puts("-1"), 0;

	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			if (!a[i][j] && d[0][i] + d[1][j] + 1 >= Mn && d[1][i] + d[0][j] + 1 >= Mn) res ++;
		}
	}

	printf("%d\n", res);
	return 0;
}