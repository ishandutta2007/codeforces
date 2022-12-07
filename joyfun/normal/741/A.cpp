#include<bits/stdc++.h>
using namespace std;

const int N = 105;

int n, c[N], vis[N];

long long lcm(long long a, long long b) {
	return a / __gcd(a, b) * b;
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	long long ans = 1;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		int u = c[i];
		long long cnt = 1;
		while (!vis[u] && u != i) {
			vis[u] = 1;
			u = c[u];
			cnt++;
		}
		if (cnt % 2 == 0) cnt /= 2;
		ans = lcm(ans, cnt);
		if (u != i) {
			printf("-1\n");
			return 0;
		}
	}
	printf("%lld\n", ans);
	return 0;
}