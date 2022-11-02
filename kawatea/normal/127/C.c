#include <stdio.h>

int main()
{
    int t1, t2, x1, x2, t0, x, y, i;
    double m;

    scanf("%d %d %d %d %d", &t1, &t2, &x1, &x2, &t0);

    if (t2 == t0) {
	if (t1 == t2) {
	    printf("%d %d\n", x1, x2);
	} else {
	    printf("%d %d\n", 0, x2);
	}

	return 0;
    }

    if (t1 == t0) {
	printf("%d %d\n", x1, 0);

	return 0;
    }

    for (i = x1; i > 0; i--) {
	long long p = (long long)(t0 - t1) * i;

	if (p % (t2 - t0) == 0 && p / (t2 - t0) <= x2) {
	    printf("%d %d\n", i, (int)(p / (t2 - t0)));

	    return 0;
	}
    }

    x = 0;
    y = x2;
    m = t2;

    for (i = x1; i >= 0; i--) {
	long long p = (long long)(t0 - t1) * i / (t2 - t0) + 1;

	if (p <= x2) {
	    double q = ((double)t1 * i + (double)t2 * p) / (i + p);

	    if ((p * x != (long long)i * y) && q < m || (q == m && x + y < i + p)) {
		x = i;
		y = p;
		m = q;
	    }
	}
    }

    printf("%d %d\n", x, y);

    return 0;
}