#include <cstdio>
#include <algorithm>

using namespace std;

int a[32];
int d[32][4004][80];
int b[80], c[80], bn;
char r[88][88], v[88][88];

int main() {
	int i, j, k, l, m, n, t;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	d[0][0][0] = 1;
	for (i = 1; i <= n; i++) for (j = 0; j < 4000; j++) for (k = 1; k < 80; k++) {
		if (k * (k - 1) / 2 <= j) for (l = 1; l <= k; l++) if (j >= l * a[i] && d[i - 1][j - l * a[i]][k - l]) {
			d[i][j][k] = 1;
			break;
		}
	}
	for (i = 1; i * (i - 1) / 2 < 4000; i++) if (d[n][i * (i - 1) / 2][i]) break;
	if (i * (i - 1) / 2 >= 4000) {
		puts("=(");
		return 0;
	}
	j = i * (i - 1) / 2; k = i; i = n;
	while (i) {
		for (l = 1; l <= k; l++) if (j >= l * a[i] && d[i - 1][j - l * a[i]][k - l]) break;
		for (t = 0; t < l; t++) b[bn++] = a[i];
		j -= l * a[i];
		k -= l;
		i = i - 1;
	}
	for (i = 0; i < bn; i++) c[i] = bn - b[i] - 1;
	for (i = 0; i < bn; i++) for (j = 0; j < bn; j++) r[i][j] = '0';
	for (i = 0; i < bn; i++) {
		while (b[i]--) {
			k = -1;
			for (j = 0; j < bn; j++) if (i != j && !v[i][j] && (k == -1 || c[j] > c[k])) k = j;
			if (k == -1) {
				puts("lol");
				return 0;
			}
			v[i][k] = v[k][i] = 1;
			r[i][k] = '1';
			c[k]--;
		}
		for (j = 0; j < bn; j++) if (i != j && !v[i][j]) {
			v[i][j] = v[j][i] = 1;
			r[j][i] = '1';
			b[j]--;
		}
	}
	printf("%d\n", bn);
	for (i = 0; i < bn; i++) puts(r[i]);
	return 0;
}