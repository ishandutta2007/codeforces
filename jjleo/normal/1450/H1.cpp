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

int sum[maxn], inv[maxn];

inline int C(int n, int m){
	if(n < m || m < 0) return 0;
	return 1ll * sum[n] * inv[m] % p * inv[n - m] % p;
}

int n, m;
char s[maxn];

int main(){
	sum[0] = 1;for(int i = 1;i < maxn;i++) sum[i] = 1ll * sum[i - 1] * i % p;
	inv[maxn - 1] = fpow(sum[maxn - 1], p - 2);
	for(int i = maxn - 2;~i;i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % p; 
	scanf("%d%d%s", &n, &m, s + 1);
	int x = 0, y = 0, ans = 0;
	for(int i = 1;i <= n;i++){
		if(s[i] == '?') x++;
		else if(s[i] == 'b' && (i & 1) || s[i] == 'w' && !(i & 1)) y++;
	}
	for(int i = 0;i <= n;i++){
		if(!((i - n / 2) & 1)) ans = (ans + 1ll * C(x, i - y) * abs(i - n / 2)) % p;
	}
	printf("%d", 1ll * ans * fpow(p + 1 >> 1, x) % p);
}