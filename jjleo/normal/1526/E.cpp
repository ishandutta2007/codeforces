#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

const int p = 998244353;

int n, k;
int sa[maxn], rk[maxn];
int inv[maxn];

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++) scanf("%d", &sa[i]), rk[++sa[i]] = i;
	int cnt = 0;
	for(int i = 2;i <= n;i++) cnt += rk[sa[i - 1] + 1] < rk[sa[i] + 1];
	inv[1] = 1;for(int i = 2;i <= n;i++) inv[i] = 1ll * (p - p / i) * inv[p % i] % p;
	int ans = 1;
	for(int i = 1;i <= n;i++) ans = 1ll * ans * (k + cnt - i + 1) % p * inv[i] % p;
	printf("%d", ans);
}