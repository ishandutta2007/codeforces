#include <bits/stdc++.h>
#define maxn 23

using namespace std;

int n, x, y, p;
int f[1 << maxn], g[1 << maxn];

int main(){
	scanf("%d%d%d", &n, &x, &y), p = x + y;
	int m = max(x, y) + 1;
	for(int i = 1;i <= p;i++){
		for(int j = 0;j < (1 << m);j++) g[j] = 0;
		for(int j = 0;j < (1 << m);j++){
			int k = ((j << 1) | (1 << m)) ^ (1 << m);
			g[k] = max(g[k], f[j]);
			if(!(k & ((1 << x) | (1 << y)))) g[k | 1] = max(g[k | 1], f[j] + n / p + (i <= n % p));
		}
		for(int j = 0;j < (1 << m);j++) f[j] = g[j];
	}
	int ans = 0;
	for(int i = 0;i < (1 << m);i++) ans = max(ans, f[i]);
	printf("%d", ans);
}