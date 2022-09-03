#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[100000];
int c[100000];
int d[100000];

int main() {
	int i, j, k, n, m;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n * m; i++) scanf("%d", &a[i]);
	for (i = j = 0; i < n; i++) {
		while (j < n) {
			for (k = 0; k < m; k++) if (!c[k]) break;
			if (k == m) break;
			if (j + 1 < n) for (k = 0; k < m; k++) if (a[j * m + k] > a[(j + 1) * m + k]) c[k]++;
			j++;
		}
		d[i] = j;
		if (i + 1 < n) for (k = 0; k < m; k++) if (a[i * m + k] > a[(i + 1) * m + k]) c[k]--;
	}
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &i, &j);
		puts(d[i - 1] < j ? "No" : "Yes");
	}
}