#include <bits/stdc++.h>
using namespace std;
int main() {
	int q; scanf("%d", &q);
	for (; q --; ) {
		long long a, b, m, mn[55], mx[55];
		scanf("%lld %lld %lld", &a, &b, &m);
		if (a == b) {
			printf("%d %lld\n", 1, a);
			continue;
		}
		mn[0] = mx[0] = a;
		mn[1] = a + 1;
		mx[1] = a + m;
		int n = - 1;
		for (int i = 1; i < 50; ++ i) {
			if (i > 1) {
				mn[i] = mn[i - 1] * 2;
				mx[i] = mx[i - 1] * 2;
			}
			if (mn[i] <= b && b <= mx[i]) {
				n = i; break;
			} else if (b < mn[i]) break;
		}
		if (!~n) puts("-1");
		else {
			printf("%d ", n + 1);
			printf("%lld", a);
			long long prv = a;
			for (int i = 1; i < n; ++ i) {
				long long delta = max(1LL, min((b >> (n - i - 1)) - 4 * a + 2 * prv - 1, m));
				printf(" %lld", a = a * 2 + delta - prv);
				prv = delta;
			}
			printf(" %lld\n", b);
		}
	}
	return 0;
}