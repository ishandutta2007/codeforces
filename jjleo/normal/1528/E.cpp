#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

const int p = 998244353;

int n;
int f[maxn], g[maxn], h[maxn];

int main(){
	scanf("%d", &n);
	f[0] = g[0] = 1;
	for(int i = 1;i <= n;i++) f[i] = (1 + f[i - 1] + 1ll * f[i - 1] * (f[i - 1] + 1) / 2) % p;
	for(int i = 1;i <= n;i++) g[i] = (f[i] + p - f[i - 1]) % p, h[i] = (g[i] + p - g[i - 1]) % p;
	int ans = 0;
	ans = (ans + 1ll * f[n - 1] * (f[n - 1] + 1)) % p;
	if(n > 1) ans = (ans + p - 1ll * f[n - 2] * (f[n - 2] + 1) % p) % p;
	ans = (ans + (__int128)f[n - 1] * (f[n - 1] + 1) * (f[n - 1] + 2) / 3) % p;
	if(n > 1) ans = (ans + p - (__int128)f[n - 2] * (f[n - 2] + 1) * (f[n - 2] + 2) / 3 % p) % p;
	for(int i = 1;i < n;i++) ans = (ans + 1ll * h[i] * g[n - i - 1]) % p;
	printf("%d", (ans + g[n - 1]) % p);
}