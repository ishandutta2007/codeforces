#include <bits/stdc++.h>
#define maxn 5086
#define maxm 10086

using namespace std;

int n, b;
int f[maxn][maxm], g[maxn][maxm];
int a[maxn], sum[maxn];
int ans[maxn];

int main(){
	scanf("%d%d", &n, &b);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
	memset(f, 0x3f, sizeof(f)), f[0][0] = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < maxm;j++){
			if(f[i - 1][j] == 0x3f3f3f3f) continue;
			int val = b + j - (sum[i - 1] - f[i - 1][j]);
			for(int k = 0;k <= val && k <= a[i] / 2;k++){
				int jj = j + (a[i] - k) / 10;
				if(f[i][jj] > f[i - 1][j] + a[i] - k){
					f[i][jj] = f[i - 1][j] + a[i] - k;
					g[i][jj] = k;
				}
			}
		}
		//for(int j = 0;j < maxm;j++) if(f[i][j] ^ 0x3f3f3f3f) printf("%d %d %d %d--\n", i, j, f[i][j], b + j + sum[i] - f[i][j]);
	}
	int x = 0;
	for(int i = 1;i < maxm;i++){
		if(f[n][x] > f[n][i]) x = i;
	}
	printf("%d\n", f[n][x]);
	for(int i = n;i;i--){
		ans[i] = g[i][x];
		x -= (a[i] - g[i][x]) / 10;
	}
	for(int i = 1;i <= n;i++) printf("%d ", ans[i]);
}