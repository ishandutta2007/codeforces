#include <bits/stdc++.h>
#define maxn 1305

using namespace std;

int n, p;
int f[maxn], g[maxn];

int main(){
	scanf("%d%d", &n, &p);
	f[0] = 1;
	int ans = 0;
	for(int i = 1;i <= n - 1;i++){
		for(int k = maxn - 1;~k;k--){
			for(int j = 1;j < i && k - j >= 0;j++){
				f[k] = (f[k] + f[k - j]) % p;
			}
		}
		for(int j = 0;j < maxn;j++) g[j] = (f[j] + (j ? g[j - 1] : 0)) % p;
		int sum = 0;
		for(int j = 1;j < i + 1;j++){
			for(int k = j + 1;k <= i + 1;k++){
				int val = j - 1 - (k - 1);
				for(int l = 0;l < maxn;l++) if(l + val - 1 >= 0) sum = (sum + 1ll * f[l] * g[min(l + val - 1, maxn - 1)]) % p;
			}
		}
		//printf("%d %d--\n", n - i - 1, sum);
		for(int j = 1;j <= n - i - 1;j++) sum = 1ll * sum * (n - j + 1) % p;
		//for(int j = 0;j <= 3;j++) printf("%d %d--\n", j, f[j]);
		ans = (ans + sum) % p;
	}
	printf("%d", ans);
}