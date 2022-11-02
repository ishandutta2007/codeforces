#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

int main()
{
    int n, sum = 0, i;
    int a[100];

    scanf("%d", &n);

    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    qsort(a, n, sizeof(int), cmp);

    for (i = 0; i < n - 1; i++) {
	if (a[i] == a[i + 1]) {
	    sum++;

	    i++;
	}
    }

    printf("%d\n", sum / 2);

    return 0;
}