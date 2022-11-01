#include <bits/stdc++.h>
#define maxn 405

using namespace std;

int n, p;
int C[maxn][maxn], f[maxn][maxn], pw[maxn];

int main(){
	scanf("%d%d", &n, &p);
	for(int i = 0;i <= n;i++){
		C[i][0] = 1;
		for(int j = 1;j <= i;j++){
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
		}
	}
	f[0][0] = 1;
	pw[0] = 1;for(int i = 1;i <= n;i++) pw[i] = (pw[i - 1] + pw[i - 1]) % p;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= i;j++){
			for(int k = 1;k <= j;k++){
				if(i - k - 1 == 0) continue;
				f[i][j] = (f[i][j] + 1ll * f[max(0, i - k - 1)][j - k] * pw[k - 1] % p * C[j][k]) % p;
			}
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i++) ans = (ans + f[n][i]) % p;
	printf("%d", ans);
}