#include <bits/stdc++.h>
#define LL long long

const int N = 2e3 + 5;
const int M = 2e5 + 5;

int a, b, m, ans;
int u[M], v[M], deg[N], col[N][N];

int32_t main() {
	scanf("%d %d %d", &a, &b, &m);
	for(int i = 1; i <= m; ++i) {
		scanf("%d %d", &u[i], &v[i]);
		v[i] += a;
		++deg[u[i]], ++deg[v[i]];
	}
	for(int i = 1; i <= a + b; ++i)
		ans = std::max(ans, deg[i]);
	for(int i = 1; i <= m; ++i) {
		int c1, c2;
		for(c1 = 1; c1 <= ans; ++c1) if(!col[u[i]][c1]) break;
		for(c2 = 1; c2 <= ans; ++c2) if(!col[v[i]][c2]) break;
		col[u[i]][c1] = v[i];
		col[v[i]][c2] = u[i];
		if(c1 == c2) continue;
		for(int c0 = c2, x = v[i]; x; x = col[x][c0], c0 ^= c1 ^ c2)
			std::swap(col[x][c1], col[x][c2]);
	}
	printf("%d\n", ans);
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= ans; ++j)
			if(col[u[i]][j] == v[i]) {
				printf("%d ", j);
				break;
			}
	return 0;
}