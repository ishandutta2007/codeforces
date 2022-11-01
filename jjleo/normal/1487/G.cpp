#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int p = 998244353;

int n;
int c[27];
int f[405][3][3][215][215], g[405][2][2][215];

inline void add(int &x, int y){
	x += y;
	if(x >= p) x -= p;
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= 26;i++) scanf("%d", &c[i]);
	f[0][0][0][0][0] = 24 * 24;
	f[0][0][1][1][0] = 24;
	f[0][0][2][0][1] = 24;
	f[0][1][0][1][0] = 24;
	f[0][1][1][2][0] = 1;
	f[0][1][2][1][1] = 1;
	f[0][2][0][0][1] = 24;
	f[0][2][1][1][1] = 1;
	f[0][2][2][0][2] = 1;
	for(int i = 0;i < n - 2;i++){
		for(int j = 0;j <= 2;j++){
			for(int k = 0;k <= 2;k++){
				for(int l = 0;l <= 210;l++){
					for(int m = 0;m <= 210;m++){
						add(f[i + 1][k][0][l][m], 1ll * (24 - (j == 0)) * f[i][j][k][l][m] % p);
						if(j != 1) add(f[i + 1][k][1][l + 1][m], f[i][j][k][l][m]);
						if(j != 2) add(f[i + 1][k][2][l][m + 1], f[i][j][k][l][m]);
					}
				}
			}
		}	
	}
	g[0][0][0][0] = 25 * 25;
	g[0][0][1][1] = 25;
	g[0][1][0][1] = 25;
	g[0][1][1][2] = 1;
	for(int i = 0;i < n - 2;i++){
		for(int j = 0;j <= 1;j++){
			for(int k = 0;k <= 1;k++){
				for(int l = 0;l <= 210;l++){
					add(g[i + 1][k][0][l], 1ll * (25 - (j == 0)) * g[i][j][k][l] % p);
					if(j != 1) add(g[i + 1][k][1][l + 1], g[i][j][k][l]);
				}
			}
		}	
	}
	int ans = 1;
	for(int i = 1;i <= n;i++) ans = 1ll * ans * (26 - (i > 2)) % p;
	for(int i = 1;i <= 26;i++){
		for(int k = c[i] + 1;k <= 211;k++){
			for(int jj = 0;jj <= 1;jj++){
				for(int kk = 0;kk <= 1;kk++){
					add(ans, p - g[n - 2][jj][kk][k]);
				}
			}
		}
		for(int j = 1;j < i;j++){
			for(int k = c[i] + 1;k <= 211;k++){
				for(int l = c[j] + 1;l <= 211;l++){
					for(int jj = 0;jj <= 2;jj++){
						for(int kk = 0;kk <= 2;kk++){
							add(ans, f[n - 2][jj][kk][k][l]);
						}
					}
				}
			}
		}
	}
	printf("%d", ans);
}