#include <cstdio>

int main() {
	int i, n;
	scanf("%d", &n);
	printf("%d\n", n / 2);
	for (i = 1; i < n / 2; i++) printf("2 ");
	printf("%d", n % 2 + 2);
}