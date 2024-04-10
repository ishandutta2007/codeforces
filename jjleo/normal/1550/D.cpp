#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

const int p = 1e9 + 7;

int t, n, l, r;
int sum[maxn], inv[maxn];

inline int C(int n, int m){
	if(n < 0 || m < 0 || n < m) return 0;
	return 1ll * sum[n] * inv[m] % p * inv[n - m] % p;
}

int main(){
	sum[0] = 1;for(int i = 1;i < maxn;i++) sum[i] = 1ll * sum[i - 1] * i % p;
	inv[0] = inv[1] = 1;for(int i = 2;i < maxn;i++) inv[i] = 1ll * (p - p / i) * inv[p % i] % p;
	for(int i = 2;i < maxn;i++) inv[i] = 1ll * inv[i] * inv[i - 1] % p;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &l, &r);
		int last = 1, ans = 0, x = 0, y = n + 1;
		while(x + 1 < y){
			int sum = min(min(x + 1 - l, r - x - 1), min(y - 1 - l, r - y + 1));
			if(sum >= last) ans = (ans + 1ll * (sum - last + 1) * (C(y - x - 1, n / 2 - x) + (n & 1 ? C(y - x - 1, (n + 1) / 2 - x) : 0))) % p;
			last = sum + 1;
			if(x + 2 == y){
				if(x + 1 - l < r - x - 1) x++;
				else y--;
			}
			else if(min(x + 1 - l, r - x - 1) < min(y - 1 - l, r - y + 1)) x++;
			else y--;
		}
		int mn = 2e9;
		for(int i = 1;i <= n;i++) mn = min(mn, max(i - l, r - i));
		if(mn >= last && (x == n / 2 || x == (n + 1) / 2)) ans = (ans + mn - last + 1) % p;
		printf("%d\n", ans);
	}
}