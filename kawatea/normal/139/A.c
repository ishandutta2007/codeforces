#include <stdio.h>

int main()
{
    int n, i;
    int a[7];

    scanf("%d", &n);

    for (i = 0; i < 7; i++) scanf("%d", &a[i]);

    while (n) {
	for (i = 0; i < 7; i++) {
	    n -= a[i];

	    if (n <= 0) {
		printf("%d\n", i + 1);

		return 0;
	    }
	}
    }

    return 0;
}