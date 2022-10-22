#include <bits/stdc++.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int n;
int a[105], l[105];
int id[105];
int dp[105][105][2];

int main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d %d", &a[i], &l[i]);
	rep(i, n) id[i] = i;
	std::sort(id, id + n, [&] (int x, int y) { return a[x] < a[y]; });
	dp[0][0][0] = 0;
	rep(i, n) {
		rep(j, i + 1) {
			rep(k, 2) {
				int mj = -1, mk = -1;
				for (int nj = i; nj < n; ++ nj) {
					rep(nk, 2) {
						if (mj == -1 || a[id[mj]] + mk * l[id[mj]] < a[id[nj]] + nk * l[id[nj]])
							mj = nj, mk = nk;
						dp[nj + 1][mj + 1][mk] = std::max(dp[nj + 1][mj + 1][mk],
								dp[i][j][k] +
								a[id[mj]] + mk * l[id[mj]] -
								std::max((j ? a[id[j - 1]] + k * l[id[j - 1]] : -0x3f3f3f3f),
										 a[id[nj]] - (!nk) * l[id[nj]]));
					}
				}
			}
		}
	}
	int ans = 0;
	rep(j, n + 1) rep(k, 2) {
		ans = std::max(ans, dp[n][j][k]);
	}
	printf("%d\n", ans);
	return 0;
}