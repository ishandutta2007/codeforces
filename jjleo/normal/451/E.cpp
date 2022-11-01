#include <bits/stdc++.h>
#define maxn 25
using namespace std;

const int p = 1e9 + 7;

typedef long long ll;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p, y >>= 1;
	}
	return ans;
}

int inv[maxn];

inline int C(ll n, int m){
	int ans = 1;
	n %= p;
	for(int i = 1;i <= m;i++) ans = 1ll * ans * n % p, n = (p + n - 1) % p;
	return 1ll * ans * inv[m] % p;
}

int n;
ll s, a[maxn];
int ans;

int main(){
	scanf("%d%lld", &n, &s);
	inv[n] = 1;for(int i = 1;i <= n;i++) inv[n] = 1ll * inv[n] * i % p;
	inv[n] = fpow(inv[n], p - 2);
	for(int i = n - 1;~i;i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % p;
	for(int i = 1;i <= n;i++) scanf("%lld", &a[i]); 
	ans = C(s + n - 1, n - 1);
	for(int i = (1 << n) - 1;i;i--){
		ll x = s;
		int cnt = 0;
		for(int j = 1, k = 1;j <= n;j++, k <<= 1){
			if(i & k) x -= a[j] + 1, cnt++;
		}
		if(x < 0) continue;
		if(cnt & 1) ans = (ans + p - C(x + n - 1, n - 1)) % p; 
		else ans = (ans + C(x + n - 1, n - 1)) % p; 
	}
	printf("%d", ans);
}