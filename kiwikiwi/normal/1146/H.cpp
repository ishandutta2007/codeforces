#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define maxN 666

int n, p[maxN][maxN], quad[maxN];
bool alive[maxN];

i64 x[maxN], y[maxN], px[maxN], py[maxN];

int gopos[maxN][maxN], goneg[maxN][maxN], f[maxN], id[maxN];
i64 dp[maxN][maxN][4], ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", &x[i], &y[i]);
	}
	for (int i = 1; i <= n; i++) {
		auto getquad = [&](int px, int py) {
			if (px == 0 && py == 0) return 0;
			if (py < 0 || (py == 0 && px < 0)) return 1;
			return 2;
		};
		for (int j = 1; j <= n; j++) {
			px[j] = x[j] - x[i];
			py[j] = y[j] - y[i];
			p[i][j] = j;
			quad[j] = getquad(px[j], py[j]);
		}
		for (int j = 1; j <= n; j++) {
			px[j + n] = x[i] - x[j];
			py[j + n] = y[i] - y[j];
			p[i][j + n] = j + n;
			quad[j + n] = getquad(px[j + n], py[j + n]);
		}
		sort(p[i] + 1, p[i] + 2 * n + 1, [&](int a, int b) {
			return quad[a] != quad[b] ? quad[a] < quad[b] :
			       (px[a] * py[b] < px[b] * py[a]);
		});
		for (int j = 1; j <= 2 * n; j++)
			if (p[i][j] > n)
				p[i][j] = n - p[i][j];
	}
	for (int i = 1; i <= n; i++) {
		int m = 0;
		for (int j = 1; j <= n; j++) {
			if (y[j] > y[i] || (y[j] == y[i] && x[j] >= x[i])) alive[j] = 1;
			else alive[j] = 0;
			px[j] = x[j] - x[i];
			py[j] = y[j] - y[i];

			if (alive[j] && j != i) {
				f[++m] = j;
			}
		}
		sort(f + 1, f + m + 1, [&](int a, int b) {
			return px[a] * py[b] < px[b] * py[a];
		});
		f[0] = i;
		for (int i = 0; i <= m; i++) id[f[i]] = i;

		memset(gopos, -1, sizeof(gopos));
		memset(goneg, -1, sizeof(goneg));
		for (int i = 0; i <= m; i++) {
			int nxtpos = -1;
			for (int j = 4 * n; j >= 1; j--) {
				int aj = (j - 1) % (2 * n) + 1;
				int u = p[f[i]][aj];
				if (u > 0 && alive[u] && nxtpos >= 0) {
					gopos[i][id[u]] = nxtpos;
				}
				if (u < 0 && alive[-u] && nxtpos >= 0) {
					goneg[i][id[-u]] = nxtpos;
				}
				if (u > 0 && alive[u] && u != f[i]) {
					nxtpos = id[u];
				}
			}
		}
		memset(dp, 0, sizeof(dp));
		dp[0][1][0] = 1;
		for (int i = 0; i <= m; i++) {
			int u = goneg[i][0];
			for (int j = 0; j < m - 1; j++) {
				int v = gopos[i][u];
				for (int k = 0; k <= 3; k++) {
					dp[i][v][k] += dp[i][u][k];
				}
				u = v;
			}
			for (int j = i + 1; j <= m; j++) {
				ans += dp[i][j][3];
				int nxt = goneg[j][i];
				if (nxt > j) {
					for (int k = 0; k <= 2; k++) {
						dp[j][nxt][k + 1] += dp[i][j][k];
					}
				}
			}
		}
	}
	printf("%lld\n", ans);
}