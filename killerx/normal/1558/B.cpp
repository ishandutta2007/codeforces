#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 4e6 + 5;

int n, mod;
int f[mxn];

void uadd(int &x, int y) {
	x += y - mod;
	x += (x >> 31) & mod;
}

void update(int l, int r, int x) {
	if (l <= n) uadd(f[l], x);
	if (r + 1 <= n) uadd(f[r + 1], mod - x);
}

int main() {
	scanf("%d %d", &n, &mod);
	/*
	f[1] = 1;
	for (int i = 2; i <= n; ++ i) {
		for (int j = 1; j <= i; ++ j)
			uadd(f[i], f[i - j]);
		for (int j = 2; j <= i; ++ j)
			uadd(f[i], f[i / j]);
	}
	eprintf("%d\n", f[n]);
	*/
	memset(f, 0, sizeof(f));
	update(1, 1, 1);
	for (int i = 1; i <= n; ++ i) {
		uadd(f[i], f[i - 1]);
		update(i + 1, n, f[i]);
		for (int k = 2; i * k <= n; ++ k)
			update(i * k, (i + 1) * k - 1, f[i]);
	}
	printf("%d\n", f[n]);
	return 0;
}