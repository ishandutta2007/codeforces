#include <bits/stdc++.h>
#define maxn 130086

using namespace std;

int n, p;
int f[maxn], g[maxn], h[maxn];

int main(){
	scanf("%d%d", &n, &p);
	f[0] = 1;
	for(int i = 0;i < maxn;i++) g[i] = 1;
	int ans = 0;
	for(int i = 1;i <= n - 1;i++){
		for(int j = maxn - 1;~j;j--) f[j] = (g[j] + p - (j - i < 0 ? 0 : g[j - i])) % p;
		for(int j = 0;j < maxn;j++) g[j] = (f[j] + (j ? g[j - 1] : 0)) % p, h[j] = (g[j] + (j ? h[j - 1] : 0)) % p;
		int sum = 0, val = 0;
		for(int j = 0;j < maxn;j++){
			if(j - 2 >= 0) val = (val + 1ll * i * g[j - 2]) % p;
			if(j - 3 >= 0) val = (1ll * val + (j - i - 3 < 0 ? 0 : h[j - i - 3]) + p - h[j - 3]) % p;
			sum = (sum + 1ll * f[j] * val) % p;
		}
		//printf("%d %d--\n", n - i - 1, sum);
		for(int j = 1;j <= n - i - 1;j++) sum = 1ll * sum * (n - j + 1) % p;
		//for(int j = 0;j <= 3;j++) printf("%d %d--\n", j, f[j]);
		ans = (ans + sum) % p;
	}
	printf("%d", ans);
}