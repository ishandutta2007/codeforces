#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int n, k;
int tot = 1;
int go[505][15];
int dep[505], sz[505], sum[505];
int f[505][15][505];
char s[505];

void dfs(int u) {
	int tmp[15][505];
	rep(c, 10) if (go[u][c]) {
		int v = go[u][c];
		dep[v] = dep[u] + 1;
		dfs(v);
		memset(tmp, 0, sizeof(tmp));
		rep(x, min(k, sz[u]) + 1) {
			rep(y, min(k - x, sz[v]) + 1) {
				rep(d, dep[u] + 1) {
					tmp[x + y][d] = min(tmp[x + y][d], f[u][x][d] + f[v][y][d]);
				}
			}
		}
		memcpy(f[u], tmp, sizeof(tmp));
		sz[u] += sz[v];
		sum[u] += sum[v];
	}
	sz[u] ++;
	rep(i, min(k, sz[u])) {
		rep(d, dep[u]) {
			f[u][i + 1][d] = min(f[u][i + 1][d], f[u][i][dep[u]] - (dep[u] - d) * sum[u]);
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);
	int ini = 0;
	rep(i, n) {
		int m; scanf("%s %d", s, &m);
		int l = strlen(s);
		int u = 1;
		rep(j, l) {
			int c = s[j] - '0';
			if (!go[u][c]) go[u][c] = ++ tot;
			u = go[u][c];
		}
		sum[u] += m;
		ini += l * m;
	}
	dfs(1);
	int ans = 0;
	rep(i, min(k, sz[1]) + 1) {
		ans = min(ans, f[1][i][0]);
	}
	ans += ini;
	printf("%d\n", ans);
	return 0;
}