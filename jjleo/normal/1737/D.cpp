#include <bits/stdc++.h>
#define maxn 505

using namespace std;

typedef long long ll;

int t, n, m;
int d[maxn][maxn];
int u[maxn * maxn], v[maxn * maxn], w[maxn * maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) d[i][j] = i == j ? 0 : 1e9;
		for(int i = 1;i <= m;i++){
			scanf("%d%d%d", &u[i], &v[i], &w[i]);
			d[u[i]][v[i]] = d[v[i]][u[i]] = 1;
		}
		for(int k = 1;k <= n;k++) for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		ll ans = 1e18;
		for(int i = 1;i <= m;i++) {
			for(int j = 1;j <= n;j++){
				ans = min(ans, 1ll * (min(d[u[i]][j], d[v[i]][j]) + 1 + d[j][1] + d[j][n] + 1) * w[i]);
			}
			ans = min(ans, 1ll * (min(d[1][u[i]] + d[n][v[i]], d[1][v[i]] + d[n][u[i]]) + 1) * w[i]);
		}
		printf("%lld\n", ans);
	}
}