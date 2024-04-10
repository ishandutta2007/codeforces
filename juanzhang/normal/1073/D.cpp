#include <bits/stdc++.h>
using namespace std;

#define re register int
typedef long long ll;
const int maxn = 2e5 + 10;
int n, start, a[maxn], nxt[maxn]; ll now, sum, ans;

int main() {
	scanf("%d %lld", &n, &now);
	for (re i = 1; i <= n; i++) {
		scanf("%d", a + i);
		sum += a[i], nxt[i] = i + 1;
	}
	nxt[n] = 0, start = 1;
	while (n) {
		ans += (now / sum) * n, now %= sum;
		for (re i = start, lst = 0; i; i = nxt[i]) {
			if (a[i] > now) {
				n--, sum -= a[i];
				if (i == start) {
					start = nxt[i];
				} else {
					nxt[lst] = nxt[i];
				}
			} else {
				now -= a[i], ans++, lst = i;
			}
		}
	}
	printf("%lld", ans);
	return 0;
}