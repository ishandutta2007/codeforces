#include <cstdio>

const int p = 1000000007;

int f(int x, int y) {
	int r = 1;
	while (y) {
		if (y & 1) r = (long long)r * x % p;
		x = (long long)x * x % p;
		y >>= 1;
	}
	return r;
}

int a[2002];
int d[2002];

int main() {
	int i, j, n, m, r;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	d[0] = 1;
	for (i = 1; i < n; i++) d[i] = (long long)d[i - 1] * (i + m - 1) % p * f(i, p - 2) % p;
	for (i = 0; i < n; i++) {
		r = 0;
		for (j = 0; j <= i; j++) r = (r + (long long)d[j] * a[i - j]) % p;
		printf("%d ", r);
	}
	return 0;
}