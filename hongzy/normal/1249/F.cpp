#include <bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define ucin() ios :: sync_with_stdio(0)
typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef double db;

const int N = 410;

int n, k, a[N], dp[N][N - 1], g[N];
vector<int> G[N];
void dfs(int u, int fa = 0) {
	dp[u][0] = a[u];
	for(int v : G[u]) if(v != fa) {
		dfs(v, u);
		fill(g, g + n + 1, 0);
		for(int i = 0; i <= n; i ++) {
			for(int j = 0; j <= n - i; j ++) if(i + j + 1 > k) {
				int &f = g[min(i, j + 1)];
				f = max(f, dp[u][i] + dp[v][j]);
			}
		}
		for(int i = 0; i <= n; i ++)
			dp[u][i] = max(dp[u][i], g[i]);
	}
}
int main() {
	ucin();
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1, u, v; i < n; i ++) {
		cin >> u >> v;
		G[u].pb(v); G[v].pb(u);
	}
	dfs(1);
	int ans = 0;
	for(int i = 0; i <= n; i ++)
		ans = max(ans, dp[1][i]);
	cout << ans << endl;
	return 0;
}