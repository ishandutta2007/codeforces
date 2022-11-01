#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

const int p = 998244353;

int n;
int x[maxn], y[maxn], s[maxn];
int f[maxn], sum[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d%d%d", &x[i], &y[i], &s[i]);
	}
	f[1] = sum[1] = (x[1] - y[1]) % p;
	for(int i = 2;i <= n;i++){
		int j = lower_bound(x + 1, x + 1 + n, y[i]) - x;
		f[i] = (1ll * x[i] - y[i] + sum[i - 1] + p - sum[j - 1]) % p;
		sum[i] = (sum[i - 1] + f[i]) % p;
	}
	int ans = (x[n] + 1) % p;
	for(int i = 1;i <= n;i++) if(s[i] == 1) ans = (ans + f[i]) % p;
	printf("%d", ans);
}