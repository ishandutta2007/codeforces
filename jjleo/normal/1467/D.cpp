#include <bits/stdc++.h>
#define maxn 5086

using namespace std;

const int p = 1e9 + 7;

int n, k, q;
int f[maxn][maxn], g[maxn][maxn], h[maxn];
int a[maxn];
int x, y;

int main(){
	scanf("%d%d%d", &n, &k, &q);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= n;i++) f[0][i] = 1;
	for(int i = 1;i <= k;i++){
		for(int j = 1;j <= n;j++) f[i][j] = (f[i - 1][j - 1] + f[i - 1][j + 1]) % p;
	}
	for(int i = 1;i <= n;i++) g[k][i] = 1;
	for(int i = k - 1;~i;i--){
		for(int j = 1;j <= n;j++) g[i][j] = (g[i + 1][j - 1] + g[i + 1][j + 1]) % p;
	}
	for(int i = 1;i <= n;i++) for(int j = 0;j <= k;j++) h[i] = (h[i] + 1ll * f[j][i] * g[j][i]) % p;
	int ans = 0;
	for(int i = 1;i <= n;i++) ans = (ans + 1ll * a[i] * h[i]) % p;
	while(q--){
		scanf("%d%d", &x, &y);
		ans = (ans + p - 1ll * a[x] * h[x] % p) % p;
		a[x] = y;
		ans = (ans + 1ll * a[x] * h[x]) % p;
		printf("%d\n", ans);
	}
}