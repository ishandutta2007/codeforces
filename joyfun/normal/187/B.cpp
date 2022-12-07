#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 65;
const int inf = 0x3f3f3f3f;
int n, m, r;
int g[N][N][N], Min[N][N], dp[N][N][N];

int main() {
	scanf("%d%d%d", &n, &m, &r);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			Min[i][j] = inf;
	for (int c = 1; c <= m; c++) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &g[c][i][j]);
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					g[c][i][j] = min(g[c][i][j], g[c][i][k] + g[c][k][j]);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				Min[i][j] = min(Min[i][j], g[c][i][j]);
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dp[0][i][j] = Min[i][j];
	for (int c = 1; c <= n; c++) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) dp[c][i][j] = inf;
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					dp[c][i][j] = min(dp[c][i][j], dp[c - 1][i][k] + Min[k][j]);
				}
			}
		}
	}
	int u, v, k;
	while (r--) {
		scanf("%d%d%d", &u, &v, &k);
		printf("%d\n", dp[min(n, k)][u][v]);
	}
	return 0;
}