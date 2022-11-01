#include <bits/stdc++.h>
#define maxn 1086
#define maxm 105 
using namespace std;

const int p = 7340033;

int t;
int n, K;
int dep;
int f[maxn / 10][maxn], g[maxn / 10][maxn];

int main(){
	for(int i = 0;i < maxm;i++) f[i][0] = g[i][0] = 1;
	for(int i = 1;i < maxm;i++){
		for(int j = 1;j < maxn;j++){
			for(int k = 0;k < j;k++){
				f[i][j] += 1ll * g[i - 1][k] * g[i - 1][j - 1 - k] % p;
				if(f[i][j] >= p) f[i][j] -= p;
			}
			for(int k = 0;k <= j;k++){
				g[i][j] += 1ll * f[i][k] * f[i][j - k] % p;
				if(g[i][j] >= p) g[i][j] -= p;
			}
		}
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &K), dep = 0;
		while((n & 1) && n >= 3) ++dep, n >>= 1;
		printf("%d\n", f[dep][K]);
	}
}