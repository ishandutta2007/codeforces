#include <bits/stdc++.h>
#define maxn 105

using namespace std;

int n, m, k, p;
int C[maxn][maxn];
int f[maxn][maxn][maxn];
int sum[maxn];

inline void add(int &x, int y){
	x += y;
	if(x >= p) x -= p;
}

int dfs(int n, int m, int k){
	if(n + 1 < k * 2) return 0;
	if(n == 0) return k == 0;
	if(m == 0) return k == 0 ? sum[n] : 0;
	if(f[n][m][k] != -1) return f[n][m][k];
	int sum = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= k - (m == 1);j++){
			add(sum, 1ll * C[n - 1][i - 1] * dfs(i - 1, m - 1, j) % p * dfs(n - i, m - 1, k - (m == 1) - j) % p);
		}
	}
	//printf("%d %d %d %d--\n", n, m, k, sum);
	return f[n][m][k] = sum;
}

int main(){
	scanf("%d%d%d%d", &n, &m, &k, &p);
	if(p == 1) return printf("0"), 0;
	sum[0] = 1;for(int i = 1;i <= n;i++) sum[i] = 1ll * sum[i - 1] * i % p;
	for(int i = 0;i <= n;i++){
		C[i][0] = 1;
		for(int j = 1;j <= i;j++) add(C[i][j], C[i - 1][j]), add(C[i][j], C[i - 1][j - 1]);
	}
	memset(f, -1, sizeof(f));
	printf("%d", dfs(n, m, k));
}