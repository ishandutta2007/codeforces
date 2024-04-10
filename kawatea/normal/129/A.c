#include <stdio.h>

int main()
{
    int n, p = 0, sum = 0, i;
    int a[100];

    scanf("%d", &n);

    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    for (i = 0; i < n; i++) {
	sum += a[i];

	if (a[i] % 2 == 0) p++;
    }

    if (sum % 2 == 0) {
	printf("%d\n", p);
    } else {
	printf("%d\n", n - p);
    }

    return 0;
}