#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

int main()
{
    int n, i, j;
    int a[100000], b[100000] = {0};

    scanf("%d", &n);

    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    if (n % 2 == 1) {
	puts("NO");

	return 0;
    }

    qsort(a, n, sizeof(int), cmp);

    for (i = 0; i < n; i++) {
	if (a[i] - a[0] >= n) {
	    puts("NO");

	    return 0;
	}

	b[a[i] - a[0]]++;
    }

    for (i = 0; i <= a[n - 1] - a[0]; i++) {
	if (b[i] == 0) {
	    puts("NO");

	    return 0;
	}
    }

    for (i = 0; i < a[n - 1] - a[0]; i++) {
	if (b[i] > b[i + 1]) {
	    if (i + 1 == a[n - 1] - a[0] && b[i] + 1 == b[i + 1]) {
		b[i] = b[i + 1] = 0;

		break;
	    }

	    puts("NO");

	    return 0;
	}

	if (b[i] == b[i + 1]) {
	    if (i + 1 == a[n - 1] - a[0]) {
		b[i] = b[i + 1] = 0;

		break;
	    }

	    puts("NO");

	    return 0;
	}

	b[i + 1] -= b[i];
	b[i] = 0;
    }

    for (i = 0; i <= a[n - 1] - a[0]; i++) {
	if (b[i] > 0) {
	    puts("NO");

	    return 0;
	}
    }

    puts("YES");

    return 0;
}