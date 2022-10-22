#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10, P = 998244353;
int n, inv[maxn];

int main() {
	int frac = 1;
	scanf("%d", &n);
	if (n == 1) return puts("1"), 0;
	for (int i = 2; i <= n; i++) {
		frac = 1ll * frac * i % P;
	}
	int res = 1ll * (n - 1) * frac % P, frac_inv = 1;
	inv[1] = 1;
	for (int i = 2; i < n; i++) {
		inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
		res = (res - 1ll * frac * (frac_inv = 1ll * inv[i] * frac_inv % P) % P + P) % P;
	}
	printf("%d", res);
	return 0;
}