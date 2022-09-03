#include <cstdio>

const int M = 1000000007;

int a[1000001];
int b[1000001];

int f(int x, int y) {
	return y ? y & 1 ? (long long)f(x, y ^ 1) * x % M : f((long long)x * x % M, y >> 1) : 1;
}

int nCr(long long n, int r) {
	return n < r ? 0 : (long long)a[n] * b[r] % M * b[n - r] % M;
}

int main() {
	int p, q;
	int i, x, y, z;
	a[0] = 1;
	for (i = 1; i <= 1000000; i++) a[i] = (long long)i * a[i - 1] % M;
	b[1000000] = 397802501;
	for (i = 1000000; i >= 1; i--) b[i - 1] = (long long)b[i] * i % M;

	scanf("%d%d%d", &x, &y, &z);

	q = 0;
	if (x == 0) q++;
	if (y == 0) q++;
	for (i = 2; i <= 200000; i++) {
		q = (q + (long long)nCr(x - 1, (i + 1) / 2 - 1) * nCr(y - 1, i / 2 - 1)) % M;
		q = (q + (long long)nCr(x - 1, i / 2 - 1) * nCr(y - 1, (i + 1) / 2 - 1)) % M;
	}

	p = 0;
	if (x == 0 && y > z) p++;
	if (y == 0) p++;
	for (i = 2; i <= 200000; i++) {
		p = (p + (long long)nCr(x - 1, (i + 1) / 2 - 1) * nCr(y - (long long)i / 2 * z - 1, i / 2 - 1)) % M;
		p = (p + (long long)nCr(x - 1, i / 2 - 1) * nCr(y - (long long)(i + 1) / 2 * z - 1, (i + 1) / 2 - 1)) % M;
	}

	printf("%lld", (long long)p * f(q, M - 2) % M);
}