#include <bits/stdc++.h>
#define maxn 1086

using namespace std;

const int p = 1e9 + 7;

int n, m;
int f[11][maxn][maxn], g[11][maxn][maxn];

int main(){
	scanf("%d%d", &n, &m);
	f[0][1][1] = 1;
	for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) g[0][i][j] = 1;
	for(int k = 1;k <= m;k++){
		for(int i = 1;i <= n;i++){
			for(int j = n;j >= i;j--){
				f[k][i][n + 1 - j] = g[k - 1][i][n + 1 - j];
				//printf("%d %d %d %d--\n", k, i, j, f[k][i][n + 1 - j]);
				g[k][i][n + 1 - j] = (1ll * f[k][i][n + 1 - j] + g[k][i - 1][n + 1 - j] + g[k][i][n + 1 - j - 1] - g[k][i - 1][n + 1 - j - 1] + p) % p;
			}
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			ans += f[m][i][n + 1 - j];
			if(ans >= p) ans -= p;
		}
	}
	printf("%d", ans);
}