#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

const int p = 998244353;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p;
		y >>= 1;
	}
	return ans;
} 

int sum[maxn];
int inv[maxn];

int n, m;

int main(){
	scanf("%d%d", &n, &m);
	if(n == 2) return printf("0"), 0;
	sum[0] = inv[0] = 1;for(int i = 1;i <= m;i++) sum[i] = 1ll * sum[i - 1] * i % p, inv[i] = fpow(sum[i], p - 2);
	printf("%d", 1ll * sum[m] * inv[n - 1] % p * inv[m - n + 1] % p * fpow(2, n - 3) % p * (n - 2) % p);
}