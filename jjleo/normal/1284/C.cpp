#include <bits/stdc++.h>
#define maxn 250086

using namespace std;

int n, p;
int sum[maxn];

int main(){
	scanf("%d%d", &n, &p);
	sum[0] = 1;for(int i = 1;i <= n;i++) sum[i] = 1ll * sum[i - 1] * i % p;
	int ans = 0;
	for(int i = 1;i <= n;i++) ans = (ans + 1ll * (n - i + 1) * (n - i + 1) % p * sum[i] % p * sum[n - i]) % p;
	printf("%d", ans);
}