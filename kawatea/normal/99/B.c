#include <stdio.h>

int main()
{
    int n, sum = 0, f = 0, x = 0, y = 0, i;
    int a[1000];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
	scanf("%d", &a[i]);

	sum += a[i];
    }

    if (sum % n != 0) {
	puts("Unrecoverable configuration.");

	return 0;
    }

    for (i = 0; i < n; i++) {
	if (a[i] != sum / n) {
	    f++;

	    if (f >= 3) {
		puts("Unrecoverable configuration.");

		return 0;
	    }

	    if (f == 1) {
		x = i;
	    } else {
		y = i;
	    }
	}
    }

    if (f == 0) {
	puts("Exemplary pages.");

	return 0;
    }

    if (f != 2) {
	puts("Unrecoverable configuration.");

	return 0;
    }

    if (sum / n * 2 == a[x] + a[y]) {
	if (a[x] > a[y]) {
	    printf("%d ml. from cup #%d to cup #%d.\n", a[x] - sum / n, y + 1, x + 1);
	} else {
	    printf("%d ml. from cup #%d to cup #%d.\n", a[y] - sum / n, x + 1, y + 1);
	}
    }

    return 0;
}