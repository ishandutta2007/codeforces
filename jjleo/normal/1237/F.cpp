#include <bits/stdc++.h>
#define maxn 4086

using namespace std;

const int p = 998244353;

int n, m, k;
int a[maxn], b[maxn], f[maxn][maxn], g[maxn][maxn];
int x, y;
int sum[maxn], inv[maxn];

inline int C(int n, int m){
	if(n < m || n < 0 || m < 0) return 0;
	return 1ll * sum[n] * inv[m] % p * inv[n - m] % p;
}

int main(){
	sum[0] = 1;for(int i = 1;i < maxn;i++) sum[i] = 1ll * sum[i - 1] * i % p;
	inv[0] = inv[1] = 1;for(int i = 2;i < maxn;i++) inv[i] = 1ll * (p - p / i) * inv[p % i] % p;
	for(int i = 2;i < maxn;i++) inv[i] = 1ll * inv[i - 1] * inv[i] % p;
	scanf("%d%d%d", &n, &m, &k);
	while(k--) for(int i = 1;i <= 2;i++) scanf("%d%d", &x, &y), a[x] = b[y] = 1;
	f[0][0] = g[0][0] = 1;
	for(int i = 1;i <= n;i++) for(int j = 0;j <= n / 2;j++){
		f[i][j] = f[i - 1][j];
		if(i >= 2 && !a[i] && !a[i - 1] && j) f[i][j] = (f[i][j] + f[i - 2][j - 1]) % p;
	}
	for(int i = 1;i <= m;i++) for(int j = 0;j <= m / 2;j++){
		g[i][j] = g[i - 1][j];
		if(i >= 2 && !b[i] && !b[i - 1] && j) g[i][j] = (g[i][j] + g[i - 2][j - 1]) % p;
	}
	int N = 0, M = 0;
	for(int i = 1;i <= n;i++) N += a[i];
	for(int i = 1;i <= m;i++) M += b[i];
	int ans = 0;
	for(int i = 0;i <= n / 2;i++) for(int j = 0;j <= m / 2;j++) ans = (ans + 1ll * f[n][i] * g[m][j] % p * C(m - M - j * 2, i) % p * C(n - N - i * 2, j) % p * sum[i] % p * sum[j]) % p;
	printf("%d", ans);
}