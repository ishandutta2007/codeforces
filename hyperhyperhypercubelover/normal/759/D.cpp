#include <cstdio>

const int p = 1000000007;

char a[5005];
int c[5005][26];
int d[5005];

int main() {
	int i, j, k, n;
	scanf("%d%s", &n, a + 1);
	d[0] = 1;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			k = (d[j - 1] - c[j][a[i] - 'a'] + p) % p;
			c[j][a[i] - 'a'] = (c[j][a[i] - 'a'] + k) % p;
			d[j] = (d[j] + k) % p;
		}
	}
	printf("%d", d[n]);
}