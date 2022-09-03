#include <cstdio>

int a[100001];
int c[100001];
long long d[100001];

int main() {
	double r = 0;
	int i, j, k, n;
	scanf("%d", &n);
	if (n == 1) {
		puts("0");
		return 0;
	}
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (i = n; i >= 1; i--) {
		for (j = a[i]; j; j &= j - 1) {
			r += c[j];
			r -= 2. * i * d[j] / n / (n + 1);
		}
		for (j = a[i]; j <= n; j += j & -j) {
			c[j]++;
			d[j] += n - i + 1;
		}
		r += (n - i + 1.) * i * (i - 1) / n / (n + 1) / 2;
	}
	printf("%.12f", r);
}