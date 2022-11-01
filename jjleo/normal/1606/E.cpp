#include <bits/stdc++.h>
#define maxn 505

using namespace std;

const int p = 998244353;

int n, x;
int f[maxn][maxn];
int C[maxn][maxn], pw[maxn][maxn];

int main(){
	scanf("%d%d", &n, &x);
	for(int i = 0;i <= n;i++){
		C[i][0] = 1;
		for(int j = 1;j <= i;j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p; 
	}
	for(int i = 1;i <= x;i++){
		pw[i][0] = 1;
		for(int j = 1;j <= n;j++) pw[i][j] = 1ll * pw[i][j - 1] * i % p; 
	}
	for(int i = 0;i <= x;i++) f[0][i] = 1;
	for(int i = 2;i <= n;i++){
		for(int j = 1;j <= x;j++){
			for(int k = 0;k <= i;k++){
				f[i][j] = (f[i][j] + 1ll * C[i][k] * pw[min(i - 1, j)][k] % p * (j - (i - 1) < 0 ? (i - k == 0) : f[i - k][j - (i - 1)])) % p;
			}
			//printf("%d %d %d--\n", i, j, f[i][j]);
		}
	}
	printf("%d", f[n][x]);
}