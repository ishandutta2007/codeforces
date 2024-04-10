#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

const int p = 998244353;

int n, k;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p, y >>= 1;
	}
	return ans;
}

int sum[maxn], inv[maxn];
int ans;

inline int C(int n, int m){
	return 1ll * sum[n] * inv[m] % p * inv[n - m] % p;
}

int main(){
	scanf("%d%d", &n, &k);
	sum[0] = 1;for(int i = 1;i <= n;i++) sum[i] = 1ll * sum[i - 1] * i % p;
	inv[n] = fpow(sum[n], p - 2);for(int i = n - 1;i >= 0;i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % p;
	if(n < k) return printf("0"), 0;
	for(int i = 1;i <= n;i++){
		if(n / i < k) break;
		ans += C(n / i - 1, k - 1);
		if(ans >= p) ans -= p;
	}
	printf("%d", ans);
}