#include <stdio.h>

int main()
{
    int n, c = 0, i;
    int a[5000] = {0};

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
	int x;

	scanf("%d", &x);

	a[x - 1]++;
    }

    for (i = 0; i < n; i++) {
	if (a[i] == 0) c++;
    }

    printf("%d\n", c);

    return 0;
}