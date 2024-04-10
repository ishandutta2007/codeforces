#include <cstdio>

int main()
{
	int i, a, b;
	scanf("%d%d", &a, &b);
	for (i = 0;; i++) if (i / 2 >= a && i / 3 >= b && i / 2 + i / 3 - i / 6 >= a + b) break;
	printf("%d", i);
}