#include <bits/stdc++.h>
#define maxn 255

using namespace std;

const int p = 998244353;

int n, m;
int f[maxn][maxn], pw[maxn][maxn * maxn], C[maxn][maxn], sum[maxn][maxn];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= m;i++){
		pw[i][0] = 1;
		for(int j = 1;j <= n * n;j++) pw[i][j] = 1ll * pw[i][j - 1] * i % p;
	}
	for(int i = 0;i <= n;i++){
		C[i][0] = 1;
		for(int j = 1;j <= i;j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p; 
	}
	n--;
	for(int i = 0;i <= m;i++) sum[0][i] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			for(int k = 1;k <= i;k++){
				f[i][j] = (f[i][j] + 1ll * C[i][k] * sum[i - k][j - 1] % p * pw[m - j + 1][(i - k + i - 1) * k / 2]) % p;
			}
			sum[i][j] = (sum[i][j - 1] + f[i][j]) % p;
		}
	}
	printf("%d", sum[n][m]); 
}