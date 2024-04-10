#include <bits/stdc++.h>

int Query(int l, int r) {
	printf("? %d %d\n", l, r);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}

int ans[310], rev[310];

int main() {
	int n, a, b, i, j;
	scanf("%d %d", &n, &a);
	if (n == 1) {
		ans[1] = a;
	} else if (n & 1) {
		for (b = a; b == a; b = Query(1, n - 1))
			Query(1, n - 1);
		ans[n] = b < a;
		rev[n] = 1;
		for (i = n - 1; i >= 1; i --) {
			for (a = b; b == a; b = Query(i, i + 1))
				Query(i, i + 1);
			for (j = 1; j <= n; j ++)
				rev[j] ^= j < i || j > i + 1;
			ans[i] = (a + b - n) / 2 + 1 - (ans[i + 1] ^ rev[i + 1]) ^ rev[i];
		}
	} else {
		for (i = n, b = a; i >= 1; i --) {
			for (a = b; b == a; b = Query(i, i))
				Query(i, i);
			for (j = 1; j <= n; j ++)
				rev[j] ^= j < i || j > i;
			ans[i] = (a + b - n + 1) / 2 ^ rev[i];
		}
	}
	printf("! ");
	for (int i = 1; i <= n; i ++)
		printf("%d", ans[i]);
	fflush(stdout);
}