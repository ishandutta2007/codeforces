#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int mo = 1e9 + 7;
const int N = 1e5 + 10;
int n, m, k, x, ans, dp[N][11][3], g[11][3]; //0:, ; 1:, ; 2:; 
vector<int> G[N];
int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = 1ll * a * a % mo)
		if(b & 1) ans = 1ll * ans * a % mo;
	return ans;
}
void upd(int &x, const int &y) {
	(x += y) >= mo ? x -= mo : 0;
}
void dfs(int u, int fa = 0) {
	memset(dp[u], 0, sizeof (dp[u]));
	dp[u][0][0] = dp[u][1][2] = 1;
	for(int v : G[u]) if(v != fa) {
		dfs(v, u);
		memset(g, 0, sizeof g);
		for(int i = 0; i <= x; i ++) {
			for(int j = 0; j <= x - i; j ++) {
				upd(g[i + j][0], 1ll * dp[u][i][0] * dp[v][j][0] % mo * m % mo);
				upd(g[i + j][0], 1ll * dp[u][i][0] * dp[v][j][1] % mo * k % mo);
				upd(g[i + j][1], 1ll * dp[u][i][0] * dp[v][j][2] % mo);
				upd(g[i + j][1], 1ll * dp[u][i][1] * dp[v][j][0] % mo * m % mo);
				upd(g[i + j][1], 1ll * dp[u][i][1] * dp[v][j][1] % mo * k % mo);
				upd(g[i + j][1], 1ll * dp[u][i][1] * dp[v][j][2] % mo);
				upd(g[i + j][2], 1ll * dp[u][i][2] * dp[v][j][0] % mo * k % mo);
				upd(g[i + j][2], 1ll * dp[u][i][2] * dp[v][j][1] % mo * k % mo);
			}
		}
		for(int i = 0; i <= x; i ++)
			for(int j = 0; j < 3; j ++)
				dp[u][i][j] = g[i][j];
	}
}
int main() {
	scanf("%d%d", &n, &m); m --;
	for(int u, v, i = 1; i < n; i ++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u); 
	}
	scanf("%d%d", &k, &x); k --;
	dfs(1);
	for(int i = 0; i <= x; i ++) {
		upd(ans, 1ll * dp[1][i][0] * m % mo);
		upd(ans, 1ll * dp[1][i][1] * k % mo);
		upd(ans, dp[1][i][2]);
	}
	printf("%d\n", ans);
	return 0;
}