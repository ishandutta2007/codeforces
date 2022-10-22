#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll q[1000000], w[1000000];
ll gcd(ll a, ll b) {
	while (b != 0)a %= b, a ^= b ^= a ^= b;
	return a;
}
int main() {
	ll g = 0, a, b;
	int n;
	ll i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%lld%lld", q+i, w+i);
		g = gcd(g, q[i]*w[i] / gcd(q[i], w[i]));
	}
	if (g == 1) {
		printf("-1"); getchar(); getchar(); return 0;
	}
	if (gcd(g, q[0]) != 1)g = gcd(g, q[0]);
	else g = gcd(g, w[0]);
	for (i = 2; i*i <= g; i++) {
		if (g%i == 0) {
			printf("%lld", i); getchar(); getchar(); return 0;
		}
	}
	printf("%lld", g);
	getchar(); getchar();
}