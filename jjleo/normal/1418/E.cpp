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

int n, m;
int d[maxn];
int sum[maxn];
int a, b;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%d", &d[i]);
	sort(d + 1, d + 1 + n);
	for(int i = 1;i <= n;i++) sum[i] = (sum[i - 1] + d[i]) % p;
	while(m--){
		scanf("%d%d", &a, &b);
		int x = lower_bound(d + 1, d + 1 + n, b) - (d + 1);// 
		int ans = 0;
		if(n - x - a + 1 > 0) ans = (ans + 1ll * sum[x] * (n - x - a + 1) % p * fpow(n - x + 1, p - 2)) % p;
		if(n - x - a > 0) ans = (ans + 1ll * (sum[n] + p - sum[x]) * (n - x - a) % p * fpow(n - x, p - 2)) % p;
		printf("%d\n", ans);
	}
}