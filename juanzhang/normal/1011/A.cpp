#include <bits/stdc++.h>
using namespace std;

const int maxn = 60;
int n, k, ans, a[maxn];

int main() {
	char buf[maxn];
	scanf("%d %d", &n, &k);
	gets(buf);
	for (int i = 1; i <= n; i++) {
		a[i] = getchar() - 'a' + 1;
	}
	sort(a + 1, a + n + 1);
	for (int p = 1, last = -1; k; ) {
		for (; p <= n && a[p] <= last + 1; p++);
		if (p > n) {
			return puts("-1"), 0;
		}
		k--, ans += a[p], last = a[p];
	}
	printf("%d", ans);
	return 0;
}