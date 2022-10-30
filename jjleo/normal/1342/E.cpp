#include <bits/stdc++.h>
#define maxn 200086

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


long long K;
int n, k;
int sum[maxn], inv[maxn];
int ans;

inline int C(int n, int m){
	return 1ll * sum[n] * inv[m] % p * inv[n - m] % p;
}

int main(){
	scanf("%d%lld", &n, &K);
	if(K >= n) return printf("0"), 0;
	k = K;
	sum[0] = 1;for(int i = 1;i <= n;i++) sum[i] = 1ll * sum[i - 1] * i % p;
	inv[n] = fpow(sum[n], p - 2);for(int i = n - 1;i >= 0;i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % p;
	for(int i = 0;i <= n - k;i++){
		int x = 1ll * C(n - k, i) * fpow(n - k - i, n) % p;
		ans += (i & 1) ? (p - x) : x;
		if(ans >= p) ans -= p;
	}//debug:(n - k)!   
	ans = 1ll * ans * C(n, n - k) % p;
	if(k) ans = (ans << 1) % p;
	printf("%d", ans);
	
}