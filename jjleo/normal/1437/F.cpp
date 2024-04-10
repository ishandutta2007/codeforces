#include <bits/stdc++.h>
#define maxn 5086

using namespace std;

const int p = 998244353; 

int n;
int a[maxn], b[maxn];
int f[maxn][maxn], sum[maxn][maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j < i;j++){
			if(a[j] * 2 <= a[i]) b[i] = j;
		}
	}
	f[0][0] = 1;
	for(int i = 0;i <= n;i++) sum[0][i] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			f[i][j] = sum[i - 1][b[j]];
			if(b[j] - i + 2 >= 0) f[i][j] = (f[i][j] + 1ll * f[i - 1][j] * (b[j] - i + 2)) % p;//debug+2  1i 1i-1 
			sum[i][j] = (sum[i][j - 1] + f[i][j]) % p;
			//printf("%d %d %d %d--\n", i, j, f[i][j], sum[i][j]);
		}
	}
	printf("%d", f[n][n]);
}