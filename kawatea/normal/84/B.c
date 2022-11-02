#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j;
    long long int c = 0;
    int a[100000];

    scanf("%d", &n);

    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    for (i = 0; i < n; i++) {
	int x = a[i];
	long long int f = 0;

	for (j = i; j < n; j++) {
	    if (a[j] == x) {
		f++;
	    } else {
		break;
	    }
	}

	i = j - 1;

	c += f * (f + 1) / 2;
    }

    printf("%I64d\n", c);

    return 0;
}