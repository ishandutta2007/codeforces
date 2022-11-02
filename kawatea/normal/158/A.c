#include <stdio.h>

int main()
{
    int n, k, i;
    int a[50];

    scanf("%d %d", &n, &k);

    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    if (a[k - 1] > 0) {
	for (i = k; i < n; i++) {
	    if (a[i] != a[k - 1]) break;
	}

	printf("%d\n", i);
    } else {
	for (i = k - 1; i >= 0; i--) {
	    if (a[i] > 0) break;
	}

	printf("%d\n", i + 1);
    }

    return 0;
}