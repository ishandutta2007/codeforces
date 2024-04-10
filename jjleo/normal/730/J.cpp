#include <bits/stdc++.h>
#define maxn 105

using namespace std;

int n;
int a[maxn], b[maxn], sum;
int f[maxn][maxn * maxn], g[maxn][maxn * maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= n;i++) scanf("%d", &b[i]);
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for(int i = 1;i <= n;i++){
		sum += a[i];
		for(int j = 0;j < maxn * maxn;j++){
			f[i][j] = f[i - 1][j];
			g[i][j] = g[i - 1][j]; 
			if(j - b[i] >= 0){
				if(f[i][j] > f[i - 1][j - b[i]] + 1){
					f[i][j] = f[i - 1][j - b[i]] + 1;
					g[i][j] = g[i - 1][j - b[i]] + a[i];
				}else if(f[i][j] == f[i - 1][j - b[i]] + 1){
					g[i][j] = max(g[i][j], g[i - 1][j - b[i]] + a[i]);
				}
			}
		}
	}
	int x = 1e9, y = 0;
	for(int i = sum;i < maxn * maxn;i++){
		if(f[n][i] < x){
			x = f[n][i], y = g[n][i];
		}else if(f[n][i] == x){
			y = max(y, g[n][i]);
		}
	}
	printf("%d %d", x, sum - y);
}