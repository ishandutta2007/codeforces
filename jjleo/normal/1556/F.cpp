#include <bits/stdc++.h>
#define maxn 14

using namespace std;

const int p = 1e9 + 7;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p, y >>= 1; 
	} 
	return ans;
}

int n;
int a[maxn], b[maxn][maxn], c[maxn][1 << maxn];
int f[1 << maxn];

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++) scanf("%d", &a[i]);
	for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) b[i][j] = 1ll * a[i] * fpow(a[i] + a[j], p - 2) % p;
	for(int i = 0;i < n;i++) for(int j = 0;j < (1 << n);j++){
		c[i][j] = 1;
		for(int k = 0;k < n;k++) if(j & (1 << k)) c[i][j] = 1ll * c[i][j] * b[i][k] % p;
	}
	int ans = 0;
	for(int i = 1;i < (1 << n);i++){
		for(int j = (i - 1) & i;j;j = (j - 1) & i){
			int val = f[j];
			for(int k = 0;k < n;k++) if(j & (1 << k)) val = 1ll * val * c[k][i ^ j] % p;
			f[i] = (f[i] + val) % p;
		}
		f[i] = (1 + p - f[i]) % p;
		int val = 1;
		for(int k = 0;k < n;k++) if(i & (1 << k)) val = 1ll * val * c[k][((1 << n) - 1) ^ i] % p;
		ans = (ans + 1ll * f[i] * val % p * __builtin_popcount(i)) % p;
	}
	printf("%d", ans);
	
}