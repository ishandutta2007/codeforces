#include <stdio.h>

int main()
{
    int n, m, s, i;

    scanf("%d %d", &n, &m);

    s = n * (n + 1) / 2;

    m %= s;

    for (i = 1; i <= n; i++) {
	if (m >= i) {
	    m -= i;
	} else {
	    break;
	}
    }

    printf("%d\n", m);

    return 0;
}