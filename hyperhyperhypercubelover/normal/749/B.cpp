#include <cstdio>

int main() {
	int a, b, c, d, e, f;
	scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
	puts("3");
	printf("%d %d\n", a + c - e, b + d - f);
	printf("%d %d\n", a - c + e, b - d + f);
	printf("%d %d\n", -a + c + e, -b + d + f);
}