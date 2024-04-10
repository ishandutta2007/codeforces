#include <bits/stdc++.h>
using namespace std;

long long T, n, k, l1, r1, l2, r2, dis, can, ans, cnt, now;

int main() {
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld%lld%lld%lld%lld%lld", &n, &k, &l1, &r1, &l2, &r2);
		dis = max(0ll, max(l2 - r1, l1 - r2));
		now = max(0ll, min(r1, r2) - max(l1, l2));
		if (now * n >= k) {
			puts("0");
			continue;
		}
		k -= now * n;
		can = max(r1, r2) - min(l1, l2) - now;
		// fprintf(stderr, "dis = %lld, can = %lld\n", dis, can);
		if (can == 0) {
			printf("%lld\n", k * 2);
			continue;
		}
		if (dis > can) {
			if (can >= k) printf("%lld\n", dis + k);
			else printf("%lld\n", dis + k * 2 - can);
		} else {
			cnt = k / can;
			if (cnt == 0) printf("%lld\n", dis + k);
			else if (cnt >= n) printf("%lld\n", (dis + can) * n + (k - can * n) * 2);
			else if (k - cnt * can >= dis) printf("%lld\n", dis * (cnt + 1) + k);
			else printf("%lld\n", (dis + can) * cnt + (k - cnt * can) * 2);
		}
	}
	return 0;
}