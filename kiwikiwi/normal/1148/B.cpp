#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define maxN 223456

int n, m, ta, tb, k;
int a[maxN], b[maxN];

int main() {
	scanf("%d%d%d%d%d", &n, &m, &ta, &tb, &k);
	int ans = 0;
	if (k >= n || k >= m) {
		printf("-1\n");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i <= k; i++) {
		int t = lower_bound(b + 1, b + m + 1, a[i + 1] + ta) - b;
		t += k - i;
		if (t > m) {
			printf("-1\n");
			return 0;
		} else {
			ans = max(ans, b[t] + tb);
		}
	}
	printf("%d\n", ans);
}