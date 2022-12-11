#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 505;

int n, m, b, mo, a[N];
int dp[2][N][N]; //dp[i][j][k] : i, \sum vi = j, \sum vi*ai = k 

void upd(int &x, const int &y) {
	(x += y) >= mo ? x -= mo : 0;
}

int main() {
	scanf("%d%d%d%d", &n, &m, &b, &mo);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	dp[0][0][0] = 1; int cur = 1;
	for(int i = 1; i <= n; i ++, cur ^= 1) {
		for(int j = 0; j <= m; j ++) {
			for(int k = 0; k <= b; k ++) {
				dp[cur][j][k] = dp[cur ^ 1][j][k];
				if(j - 1 >= 0 && k - a[i] >= 0) {
					upd(dp[cur][j][k], dp[cur][j - 1][k - a[i]]);
				}
			}
		}
	}
	int ans = 0; cur ^= 1;
	for(int i = 0; i <= b; i ++) {
		upd(ans, dp[cur][m][i]);
	}
	printf("%d\n", (ans % mo + mo) % mo);
	return 0;
}
/*
\sum v[i] = m
v[i] * a[i] <= b

*/