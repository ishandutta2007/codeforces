#include <bits/stdc++.h>
#define maxn 5086

using namespace std;

int n, m, k;

const int p = 998244353;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p, y >>= 1;
	}
	return ans;
}

int f[maxn][maxn];
int ans;
int inv;

int main(){
	scanf("%d%d%d", &n, &m, &k);
	f[0][0] = 1;
	for(int i = 1;i <= k;i++){
		for(int j = 1;j <= i;j++){
			f[i][j] = (1ll * f[i - 1][j] * j + 1ll * f[i - 1][j - 1] * (n - j + 1)) % p; 
		}
	}
	inv = fpow(m, p - 2);
	for(int i = 1;i <= k;i++) ans = (ans + 1ll * f[k][i] * fpow(inv, i) % p) % p;
	printf("%d", ans);
}