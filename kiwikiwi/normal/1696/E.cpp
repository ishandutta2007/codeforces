#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN 510000
const i64 P = 1000000007;

int n;
i64 fac[maxN], inv[maxN], ifac[maxN];

int main() {
	scanf("%d", &n);
	fac[0] = ifac[0] = 1;
	for (int i = 1; i <= 450000; i++) {
		fac[i] = fac[i - 1] * i % P;
		inv[i] = (i == 1) ? 1 : (P - P / i) * inv[P % i] % P;
		ifac[i] = ifac[i - 1] * inv[i] % P;
	}
	i64 ans = 0;
	for (int i = 1; i <= n + 1; i++) {
		int x;
		scanf("%d", &x);
		if (x > 0) {
			ans = (ans + fac[x + i - 1] * ifac[i] % P * ifac[x - 1]) % P;
		}
	}
	printf("%lld\n", ans);
}