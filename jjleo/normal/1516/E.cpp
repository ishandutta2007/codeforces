#include <bits/stdc++.h>
#define maxn 405

using namespace std;

const int p = 1e9 + 7;

int n, m;
int f[maxn][maxn], g[maxn][maxn];
int inv[maxn], ans[maxn];

int main(){
	scanf("%d%d", &n, &m);
	inv[1] = 1;for(int i = 2;i < maxn;i++) inv[i] = 1ll * (p - p / i) * inv[p % i] % p; 
	f[0][0] = 1;
	for(int i = 1;i <= min(n, 2 * m);i++){
		f[i][0] = 1;
		for(int j = 1;j <= m;j++) f[i][j] = (f[i - 1][j] + 1ll * (i - 1) * f[i - 1][j - 1]) % p;
	}
	for(int i = 0;i <= min(n, 2 * m);i++){
		for(int j = 0;j <= m;j++){
			int C = 1;
			for(int k = 0;k <= i;k++, C = 1ll * C * (i - k + 1) % p * inv[k] % p){
				g[i][j] = (g[i][j] + 1ll * (k & 1 ? p - 1 : 1) * C % p * f[i - k][j]) % p;
			}
		}
	}
	int C = 1;
	for(int i = 0;i <= min(n, 2 * m);i++, C = 1ll * C * (n - i + 1) % p * inv[i] % p){
		for(int j = 0;j <= m;j++){
			ans[j] = (ans[j] + 1ll * C * g[i][j]) % p;
		}
	}
	for(int i = 2;i <= m;i++) ans[i] = (ans[i] + ans[i - 2]) % p;
	for(int i = 1;i <= m;i++) printf("%d ", ans[i]);
}