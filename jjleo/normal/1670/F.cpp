#include <bits/stdc++.h>
#define maxn 2086

using namespace std;

const int p = 1e9 + 7;

typedef long long ll;

int n;
ll z;
int C[maxn][maxn];

int solve(ll m){
	int f[maxn][2] = {0}, g[maxn][2] = {0};
	f[0][1] = 1;
	for(int i = 0;i <= 60;i++){
		for(int j = 0;j <= n * 2;j++){
			for(int k = 0;k <= 1;k++) if(f[j][k]){
				for(int l = (z >> i) & 1;l <= n;l += 2){
					g[j + l][k] = (g[j + l][k] + 1ll * C[n][l] * f[j][k]) % p;
				}
				f[j][k] = 0;
			}
		}
		for(int j = 0;j <= n * 2;j++){
			for(int k = 0;k <= 1;k++){
				int jj = j / 2;
				int kk = (j & 1) == ((m >> i) & 1) ? k : (j & 1) < ((m >> i) & 1);
				f[jj][kk] = (f[jj][kk] + g[j][k]) % p, g[j][k] = 0;
			}
		}
	}
	return f[0][1];
}

int main(){
	ll l, r;
	scanf("%d%lld%lld%lld", &n, &l, &r, &z);
	for(int i = 0;i <= n;i++){
		C[i][0] = 1;
		for(int j = 1;j <= i;j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
	}
	printf("%d", (solve(r) + p - solve(l - 1)) % p);
}