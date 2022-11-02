#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);

    n *= 3;

    if (n % 2 == 0) {
	printf("%d\n", n / 2);
    } else {
	printf("%d\n", (n - 1) / 2);
    }

    return 0;
}