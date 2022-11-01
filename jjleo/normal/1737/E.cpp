#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

const int p = 1e9 + 7;

int t, n;
int pw[maxn];
int f[maxn], sum[maxn];
int ans[maxn];

int main(){
	pw[0] = 1;for(int i = 1;i < maxn;i++) pw[i] = 2 * pw[i - 1] % p;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		f[n + 2] = sum[n + 2] = 0;
		f[n + 1] = sum[n + 1] = 1;
		int inv = 1;
		for(int i = 1;i <= n - 1;i++) inv = 1ll * inv * (p + 1 >> 1) % p;
		for(int i = n;i;i--){
			int r = i / 2;
			ans[i] = 1ll * f[i + 1] * pw[r] % p * inv % p;
			r = min(n, (i - 1) * 2 - 1);
			f[i] = (sum[i + 1] + p - sum[r + 2]) % p;
			sum[i] = (sum[i + 1] + f[i]) % p;
		}
		for(int i = 1;i <= n;i++) printf("%d\n", ans[i]);
	}
}