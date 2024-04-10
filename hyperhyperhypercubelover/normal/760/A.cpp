#include <cstdio>

int a[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d", (a[n - 1] + m + 5) / 7);
}