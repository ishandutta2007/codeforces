#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, tot, a[maxn], b[maxn], ans[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	for (int i = 1; i <= n; i++) {
		bool flag = 1;
		memset(b, 0, sizeof b);
		for (int j = 1; j <= n; j++) {
			if (j <= i) {
				b[j - 1] = a[j] - a[j - 1];
			} else if (a[j] - a[j - 1] != b[(j - 1) % i]) {
				flag = 0; break;
			}
		}
		if (flag) ans[++tot] = i;
	}
	printf("%d\n", tot);
	for (int i = 1; i <= tot; i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}