#include <bits/stdc++.h>
#define maxn 605

using namespace std;

typedef long long ll;

int n, m, q;
int x, y, z;
ll d[maxn][maxn], f[maxn][maxn];
int u[maxn * maxn], v[maxn * maxn], w[maxn * maxn];


int main(){
	scanf("%d%d", &n, &m);
	memset(d, 0x3f, sizeof(d)), memset(f, -0x3f, sizeof(f)); 
	for(int i = 1;i <= n;i++) d[i][i] = 0;
	for(int i = 1;i <= m;i++){
		scanf("%d%d%d", &x, &y, &z);
		d[x][y] = d[y][x] = z;
		u[i] = x, v[i] = y, w[i] = z;
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	scanf("%d", &q);
	while(q--){
		scanf("%d%d%d", &x, &y, &z);
		for(int i = 1;i <= n;i++){
			f[i][x] = max(f[i][x], z - d[y][i]);
			f[i][y] = max(f[i][y], z - d[x][i]);
		}
	}
	int ans = 0;
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= n;j++){
			if(d[u[i]][j] + w[i] <= f[v[i]][j] || d[v[i]][j] + w[i] <= f[u[i]][j]){
				ans++;
				break;
			}
		}
	}
	printf("%d", ans);
}