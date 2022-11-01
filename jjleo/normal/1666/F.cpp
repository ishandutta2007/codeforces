#include <bits/stdc++.h>
#define maxn 5086

using namespace std;

const int p = 998244353;

int t, n;
int sum[maxn], inv[maxn];
int a[maxn];
int f[maxn];
int x;

int main(){
	sum[0] = 1;for(int i = 1;i < maxn;i++) sum[i] = 1ll * sum[i - 1] * i % p;
	inv[0] = inv[1] = 1;for(int i = 2;i < maxn;i++) inv[i] = 1ll * (p - p / i) * inv[p % i] % p;
	for(int i = 2;i < maxn;i++) inv[i] = 1ll * inv[i] * inv[i - 1] % p;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) a[i] = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &x), a[x]++;
		for(int i = 1;i <= n;i++) a[i] += a[i - 1];
		for(int i = 2;i <= n;i += 2){
			if(i == 2){
				for(int j = 1;j <= n;j++){
					f[j] = 1ll * sum[a[j] - a[j - 1]] * inv[a[j] - a[j - 1] - 1] % p * a[j - 1] % p;
//					printf("%d %d %d--\n", i, j, f[j]); 
				}
				continue;
			}
			int val = 0;
			for(int j = 1;j <= n;j++){
				int tmp = f[j];
				f[j] = 1ll * val * sum[a[j] - a[j - 1]] % p * inv[a[j] - a[j - 1] - 1] % p;
				if(a[j - 1] - (i - 3) >= 0) val = (val + 1ll * tmp * (a[j - 1] - (i - 3))) % p;
//				printf("%d %d %d %d--\n", i, j, val, f[j]); 
			} 
		}
		int ans = 0;
		for(int i = 1;i <= n;i++) ans = (ans + f[i]) % p;
		for(int i = 1;i <= n;i++) ans = 1ll * ans * inv[a[i] - a[i - 1]] % p;
		printf("%d\n", ans);
	}
}