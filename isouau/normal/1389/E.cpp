#include <bits/stdc++.h>
using namespace std;

int T, n, m, d, w;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &m, &d, &w);
		n = min(m, d); w /= gcd(d - 1, w);
		printf("%lld\n", 1ll * (n % w) * (n / w + 1) * (n / w) / 2 + 1ll * (w - n % w) * (n / w) * (n / w - 1) / 2);
	}
	return 0;
}