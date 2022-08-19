#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const i64 mod = 998244353;

int n;
i64 ans, fact[1234567];
int main() {
	scanf("%d", &n);
	fact[0] = 1;
	for (int i = 1; i <= n; i++)
		fact[i] = fact[i - 1] * (n + 1 - i) % mod;
	i64 ans = fact[n];
	for (int i = 1; i <= n - 2; i++) {
		ans = (ans + fact[n] - fact[i]) % mod;
	}
	if (ans < 0) ans += mod;
	printf("%lld\n", ans);
}