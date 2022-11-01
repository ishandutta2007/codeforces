#include <bits/stdc++.h>
#define maxn 100086

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

int sum[maxn], inv[maxn];
inline int C(int n, int m){
	return 1ll * sum[n] * inv[m] % p * inv[n - m] % p;
}

int n, k;

int main(){
	sum[0] = 1;for(int i = 1;i < maxn;i++) sum[i] = 1ll * sum[i - 1] * i % p;
	inv[0] = 1;for(int i = 1;i < maxn;i++) inv[i] = 1ll * inv[i - 1] * fpow(i, p - 2) % p;
	scanf("%d%d", &n, &k);
	int x = 1;for(int i = 1;i <= n;i++) x = (x + x) % p;
	for(int i = 0;i < n - k;i++) x = (x + p - C(n, i)) % p;
	printf("%d", x);
}