#include <bits/stdc++.h>
#define maxn 2000086

using namespace std;

const int p = 998244353;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p, y >>= 1;
	}
	return ans;
}

int n, m;

int sum[maxn], inv[maxn];

int main(){
	scanf("%d%d", &n, &m);
	int ans = 0;
	sum[0] = 1;for(int i = 1;i < maxn;i++) sum[i] = 1ll * sum[i - 1] * i % p;
	inv[maxn - 1] = fpow(sum[maxn - 1], p - 2);
	for(int i = maxn - 2;~i;i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % p;
	for(int i = 1;i <= n;i++) ans = (ans + 1ll * inv[i] * sum[i - 1]) % p;
	ans = (1ll * ans * m + 1) % p;
	printf("%d", 1ll * ans * (1ll * n * sum[m] % p * inv[m + 1] % p + 1) % p);
}