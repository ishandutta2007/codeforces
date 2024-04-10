#include <bits/stdc++.h>
#define maxn 20000086

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

int n, a[maxn], x, y, k, m;
int f[maxn];

int main(){
	scanf("%d%d%d%d%d%d", &n, &a[0], &x, &y, &k, &m);
	for(int i = 1;i < n;i++) a[i] = (1ll * a[i - 1] * x + y) % m;
	int lcm = 1;
	for(int i = 1;i <= k;i++) lcm = lcm * i / __gcd(lcm, i);
	int ans = 0;
	for(int i = 0;i < n;i++){
		ans += a[i] - a[i] % lcm;
		if(ans >= p) ans -= p;
		f[a[i] % lcm]++;
	}
	int inv = fpow(n, p - 2);
	ans = 1ll * ans * inv % p * k % p;
	for(int i = 1;i <= k;i++){
		int sum = 0;
		for(int j = 0;j < lcm;j++){
			sum = (sum + 1ll * j * f[j]) % p;
			int val = 1ll * inv * f[j] % p;
			int jj = j - j % i;
			f[jj] += val;
			if(f[jj] >= p) f[jj] -= p;
			f[j] -= val;
			if(f[j] < 0) f[j] += p;
		}
		ans = (ans + 1ll * sum * inv) % p;
	}
	for(int i = 1;i <= k;i++) ans = 1ll * ans * n % p;
	printf("%d", ans);
}