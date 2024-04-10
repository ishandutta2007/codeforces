#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int pos[N], a[N], b[N];
int n, m, x, k, y;
ll ans;

int main() {
	scanf("%d%d%d%d%d", &n, &m, &x, &k, &y);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), pos[a[i]] = i;
	for (int i = 1; i <= m; i++) scanf("%d", &b[i]), b[i] = pos[b[i]];
	b[++m] = n + 1;
	for (int i = 1; i <= m; i++) {
		if (b[i - 1] >= b[i]) {
			puts("-1");
			return 0;
		}
		int maxn = 0;
		for (int j = b[i - 1] + 1; j < b[i]; j++) maxn = max(maxn, a[j]);
		int len = b[i] - b[i - 1] - 1;
		if (len < k) {
			if (maxn > max(a[b[i - 1]], a[b[i]])) {
				puts("-1");
				return 0;
			}
			ans += 1ll * len * y;
		} else {
			if (1ll * y * k <= x) {
				if (maxn > max(a[b[i - 1]], a[b[i]])) ans += 1ll * (len - k) * y + x;
				else ans += 1ll * len * y;
			} else ans += 1ll * (len - len / k * k) * y + 1ll * len / k * x;
		}
	}
	printf("%lld\n", ans);
	return 0;
}