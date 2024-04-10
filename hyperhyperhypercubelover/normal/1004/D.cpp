#include <cstdio>
#include <algorithm>

using namespace std;

int a[1000001];

int main() {
	int t = 0;
	int i, j, k, l, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &j);
		if (j > t) t = j;
		a[j]++;
	}
	for (i = 0; a[i + 1] == (i + 1) * 4; i++);
	j = i;
	for (i = 1; i <= n; i++) if (n % i == 0 && j < i) {
		k = t - max(j, i - j - 1);
		if (k < 0 || k >= n / i) continue;
		for (l = 0; l < n; l++) a[abs(l % i - j) + abs(l / i - k)]--;
		for (l = 0; l <= n; l++) if (a[l]) break;
		if (l > n) {
			printf("%d %d\n", i, n / i);
			printf("%d %d\n", j + 1, k + 1);
			return 0;
		}
		for (l = 0; l < n; l++) a[abs(l % i - j) + abs(l / i - k)]++;
	}
	puts("-1");
	return 0;
}