#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 710;
const int mo = 1e9 + 7;

int n, st[N], p[N], top, pre[2][N], nxt[2][N], dp[N][N][3][3];
bool bo[N][N];

char s[N];

bool pa(int x, int y) {
	return (x >= 1) + (y >= 1) == 1;
}

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 1; i <= n; i ++) {
		if(s[i] == '(') st[++ top] = i;
		else {
			p[i] = st[top --];
			p[p[i]] = i;
		}
		if(p[i - 1] == i) bo[i - 1][i] = 1;
	}
	for(int i = n; i >= 1; i --) {
		for(int j = i + 2; j <= n; j ++) {
			bo[i][j] = p[i] == j ? bo[i + 1][j - 1] : bo[i][p[j] - 1];
		}
	}
	pre[0][0] = pre[1][0] = -1;
	nxt[0][n + 1] = nxt[1][n + 1] = -1;
	for(int i = 1; i <= n; i ++) {
		pre[0][i] = pre[0][i - 1];
		pre[1][i] = pre[1][i - 1];
		if(s[i] == '(') pre[0][i] = i;
		else pre[1][i] = i;
	}
	for(int i = n; i >= 1; i --) {
		nxt[0][i] = nxt[0][i + 1];
		nxt[1][i] = nxt[1][i + 1];
		if(s[i] == '(') nxt[0][i] = i;
		else nxt[1][i] = i;
	}
	for(int i = pre[0][n]; ~ i; i = pre[0][i - 1]) {
		for(int j = nxt[1][i]; ~ j; j = nxt[1][j + 1]) if(bo[i][j]) {
//			printf("visiting [%d, %d] :\n", i, j);
			if(p[i] == j) {
				if(i + 1 == j) {
					dp[i][j][0][1] = dp[i][j][1][0] = dp[i][j][0][2] = dp[i][j][2][0] = 1;
				} else {
					for(int l = 0; l < 3; l ++) {
						for(int r = 0; r < 3; r ++) if(pa(l, r)) {
							for(int m0 = 0; m0 < 3; m0 ++) if(!m0 || m0 != l) {
								for(int m1 = 0; m1 < 3; m1 ++) if(!m1 || m1 != r) {
									(dp[i][j][l][r] += dp[i + 1][j - 1][m0][m1]) %= mo;
								}
							}
						}
					}
				}
			} else { 
				int k = p[j];
				if(k < i) continue ;
//				printf("i = %d, k = %d, j = %d\n", i, k, j);
				for(int l = 0; l < 3; l ++) {
					for(int m0 = 0; m0 < 3; m0 ++) {
						for(int m1 = 0; m1 < 3; m1 ++) if(!(m1 && m1 == m0)) {
							for(int r = 0; r < 3; r ++) if(pa(m1, r)) {
								(dp[i][j][l][r] += dp[i][k - 1][l][m0] * 1ll * dp[k][j][m1][r] % mo) %= mo;
							}
						}
					}
				}
//				int ans = 0;
//				for(int x = 0; x < 3; x ++) {
//					for(int y = 0; y < 3; y ++) if(1) {
//						(ans += dp[i][j][x][y]) %= mo;
//					}
//				}
//				printf("ans = %d\n", ans);
			}
//			for(int x = 0; x < 3; x ++) {
//					for(int y = 0; y < 3; y ++) if(1) {
//						printf("%d, %d = %d\n", x, y, dp[i][j][x][y]);
//					}
//				}
		}
	}
	int ans = 0;
	for(int i = 0; i < 3; i ++) {
		for(int j = 0; j < 3; j ++) {
			(ans += dp[1][n][i][j]) %= mo;
		}
	}
	printf("%d\n", ans);
	return 0;
}