#include <bits/stdc++.h>
#define maxn 200086

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
	if(n < m || m < 0) return 0;
	return 1ll * sum[n] * inv[m] % p * inv[n - m] % p;
}

int t;
int n, m, k;
int a[maxn];
int b[maxn];

int main(){
	sum[0] = 1;for(int i = 1;i < maxn;i++) sum[i] = 1ll * sum[i - 1] * i % p;
	inv[maxn - 1] = fpow(sum[maxn - 1], p - 2);
	for(int i = maxn - 2;~i;i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % p;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		if(m == 1){
			printf("%d\n", n);
			continue;
		}
		sort(a + 1, a + 1 + n, greater<int>());
		for(int i = 0;i <= n;i++){
			b[i] = C(i, m - 2);
			if(i) b[i] = (b[i] + b[i - 1]) % p; 
		}
		int l = 1;
		int ans = 0;
		for(int i = 1;i <= n;i++){
			while(a[l] - a[i] > k) l++;
			if(i ^ l) ans = (ans + b[i - l - 1]) % p;
		}
		printf("%d\n", ans);
	}
}