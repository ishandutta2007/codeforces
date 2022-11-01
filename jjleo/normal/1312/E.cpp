#include <bits/stdc++.h>
#define maxn 505

using namespace std;

int n;
int a[maxn];
int f[maxn][maxn], g[maxn][maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), g[i][i] = a[i];
	memset(f, 0x3f, sizeof(f));
	for(int l = 2;l <= n;l++){
		for(int i = 1;i + l - 1 <= n;i++){
			for(int j = 1;j < i + l - 1;j++){
				if(g[i][j] && g[i][j] == g[j + 1][i + l - 1]){
					g[i][i + l - 1] = g[i][j] + 1;
					break;
				}
			}
		}
	}
	for(int l = 1;l <= n;l++){
		for(int i = 1;i + l - 1 <= n;i++){
			if(g[i][i + l - 1]) f[i][i + l - 1] = 1;
			for(int j = 1;j < i + l - 1;j++){
				f[i][i + l - 1] = min(f[i][i + l - 1], f[i][j] + f[j + 1][i + l - 1]);
			}
		}
	}
	printf("%d", f[1][n]);
}