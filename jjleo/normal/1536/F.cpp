#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

const int p = 1e9 + 7;

int n;
int sum[maxn], inv[maxn];

inline int C(int n, int m){
	if(n < m) return 0;
	return 1ll * sum[n] * inv[m] % p * inv[n - m] % p;
}

int main(){
	sum[0] = 1;for(int i = 1;i < maxn;i++) sum[i] = 1ll * sum[i - 1] * i % p;
	inv[0] = inv[1] = 1;for(int i = 2;i < maxn;i++) inv[i] = 1ll * (p - p / i) * inv[p % i] % p;
	for(int i = 2;i < maxn;i++) inv[i] = 1ll * inv[i] * inv[i - 1] % p;
	scanf("%d", &n);
	int ans = 0;
	for(int i = 0;i <= n;i++){
		if((n - i) & 1) continue;
		ans = (ans + 1ll * (C(n - i, i) + C(n - i - 1, i - 1)) * sum[n - i]) % p;
	}
	ans = (ans + ans) % p;
	printf("%d", ans);
}