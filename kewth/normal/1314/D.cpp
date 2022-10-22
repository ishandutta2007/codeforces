#pragma GCC optimize(2)
#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef std::pair<int, int> par;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 85, maxm = 12, inf = 1000000005;
bool color[maxn];
int path[maxm];
int dis[maxn][maxn];
par d[maxn][maxn][maxn];

int ans = inf;
void fuck(int y, int n, int m) {
	if(y == m) {
		for(int i = 0; i <= m; i += 2)
			color[path[i]] = 1;

		int sum = 0;
		for(int i = 2; i <= m; i += 2) {
			int x = path[i - 2], y = path[i];
			int p = 1;
			while(color[d[x][y][p].second])
				++ p;
			sum += d[x][y][p].first;
			if(sum >= inf) break;
		}
		ans = std::min(ans, sum);

		for(int i = 0; i <= m; i += 2)
			color[path[i]] = 0;
		return;
	}

	for(int i = 1; i <= n; i ++) {
		path[y] = i;
		fuck(y + 2, n, m);
	}
}

int main() {
	int n = read, m = read;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			dis[i][j] = read;

	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++) {
			for(int k = 1; k <= n; k ++)
				d[i][j][k] = par(dis[i][k] + dis[k][j], k);
			d[i][j][n + 1] = par(inf, 0);
			std::sort(d[i][j] + 1, d[i][j] + n + 1);
		}

	path[0] = path[m] = 1;
	fuck(2, n, m);
	printf("%d\n", ans);
}