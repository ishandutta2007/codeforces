#include <cstdio>

int a[100002];

int main() {
	int i, j, n;
	scanf("%d", &n);
	n++;
	for (i = 2; i <= n; i++) if (!a[i]) for (j = i + i; j <= n; j += i) a[j] = 1;
	puts(n < 4 ? "1" : "2");
	for (i = 2; i <= n; i++) printf("%d ", a[i] + 1);
}