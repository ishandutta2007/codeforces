#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 21;

int n, m, a[N][N], dp[1 << N], se[N][N], co[N][N];
char s[N + 2][N + 2];
bool vis[26]; 

void upd(int &u, const int &v) {
	u == -1 ? u = v : u = min(u, v);
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++) {
		scanf("%s", s[i] + 1);
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
//			int ma = 0;
			for(int k = 1; k <= n; k ++) if(s[i][j] == s[k][j]) {
				se[i][j] ^= 1 << (k - 1);
				if(i == k) continue ;
//				ma = max(ma, a[k][j]);
				co[i][j] += a[k][j];
			}
//			co[i][j] -= ma;
		}
	}
	fill(dp + 1, dp + (1 << n), -1); dp[0] = 0;
	for(int i = 0; i < (1 << n); i ++) {
		for(int j = 0; j < n; j ++) if(!(i >> j & 1)) {
			for(int k = 1; k <= m; k ++) {
				upd(dp[i | (1 << j)], dp[i] + a[j + 1][k]);
				upd(dp[i | se[j + 1][k]], dp[i] + co[j + 1][k]);
			}
		}
	}
	printf("%d\n", dp[(1 << n) - 1]);
	return 0;
}