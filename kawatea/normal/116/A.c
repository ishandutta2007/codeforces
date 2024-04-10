#include <stdio.h>

int main()
{
    int n, x = 0, max = 0, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
	int a, b;

	scanf("%d %d", &a, &b);

	x += b - a;

	if (x > max) max = x;
    }

    printf("%d\n", max);

    return 0;
}