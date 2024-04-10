#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int p = 1e9 + 7;

int t;
int n, k;
int sum[maxn], inv[maxn];

inline int C(long long n, int m){
	if(n < m) return 0;
	return 1ll * sum[n] * inv[m] % p * inv[n - m] % p;
}

int main(){
	sum[0] = 1;for(int i = 1;i < maxn;i++) sum[i] = 1ll * sum[i - 1] * i % p;
	inv[0] = inv[1] = 1;for(int i = 2;i < maxn;i++) inv[i] = 1ll * (p - p / i) * inv[p % i] % p;
	for(int i = 2;i < maxn;i++) inv[i] = 1ll * inv[i] * inv[i - 1] % p;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k), k--;
		int ans = 1;
		for(int i = 1;i <= n;i++) ans = (ans + 1ll * inv[n] * sum[i] % p * sum[n - i] % p * C(n - 1ll * k * i + k, i)) % p;
		printf("%d\n", ans);
	}
}