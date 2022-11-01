#include <bits/stdc++.h>
#define maxn 2000086

using namespace std;

const int p = 1e9 + 7;

int t, n, m, k;
int sum[maxn], inv[maxn], pw[maxn];

inline int C(int n, int m){
	if(n < 0 || m < 0 || n < m) return 0;
	return 1ll * sum[n] * inv[m] % p * inv[n - m] % p;
}

int main(){
	sum[0] = 1;for(int i = 1;i < maxn;i++) sum[i] = 1ll * sum[i - 1] * i % p;
	inv[0] = inv[1] = 1;for(int i = 2;i < maxn;i++) inv[i] = 1ll * (p - p / i) * inv[p % i] % p;
	for(int i = 2;i < maxn;i++) inv[i] = 1ll * inv[i - 1] * inv[i] % p;
	pw[0] = 1;for(int i = 1;i < maxn;i++) pw[i] = 1ll * pw[i - 1] * ((p + 1) >> 1) % p;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &m, &k);
		if(n == m){
			printf("%d\n", 1ll * k * n % p);
			continue;
		}
		int ans = 0;
		for(int i = 1;i <= m;i++) ans = (ans + 1ll * k * i % p * C(n - i - 1, m - i) % p * pw[n - i]) % p;
		printf("%d\n", ans);
	}
}