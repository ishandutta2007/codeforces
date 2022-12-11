#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
int n, m, lg[1 << 19], g[19][19];
ll dp[1 << 19][19];
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i ++) lg[1 << i] = i;
	for(int u, v, i = 0; i < m; i ++) {
		scanf("%d%d", &u, &v); u --; v --; g[u][v] = g[v][u] = 1;
	}
	for(int i = 0; i < n; i ++) dp[1 << i][i] = 1;
	ll ans = 0;
	for(int S = 1; S < (1 << n); S ++) {
		for(int i = 0; i < n; i ++) if(dp[S][i]) {
			int k = lg[S & (-S)];
			for(int j = k + 1; j < n; j ++) if(!(S >> j & 1) && g[i][j]) {
				dp[S | (1 << j)][j] += dp[S][i];
			}
			if(g[i][k] && S != ( (1 << k) ^ (1 << i) )) {
				ans += dp[S][i];
			}
		}
	}
	printf("%I64d\n", ans / 2);
	return 0;
}