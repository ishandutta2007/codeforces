#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k;
int f[maxn];
int b[maxn], c[maxn];
int g[maxn];

int main(){
	memset(f, 0x3f, sizeof(f));
	f[1] = 0;
	for(int n = 1;n < 1000;n++){
		for(int i = 1, j;i <= n;i = j + 1){
			j = n / (n / i);
			if(n + n / i <= 1000) f[n + n / i] = min(f[n + n / i], f[n] + 1);
		}
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		k = min(k, 12 * n);
		for(int i = 0;i <= k;i++) g[i] = i == 0 ? 0 : -1e9;
		for(int i = 1;i <= n;i++) scanf("%d", &b[i]);
		for(int i = 1;i <= n;i++) scanf("%d", &c[i]);
		for(int i = 1;i <= n;i++){
			for(int j = k;j >= f[b[i]];j--) g[j] = max(g[j], g[j - f[b[i]]] + c[i]); 
		}
		printf("%d\n", *max_element(g, g + k + 1));
	}
}