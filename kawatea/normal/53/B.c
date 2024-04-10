#include <stdio.h>

int main()
{
    int h, w, p = 1, a = 1, b = 1;
    long long x, max = 0;

    scanf("%d %d", &h, &w);

    while (p <= h) {
	if ((long long)p * 5 > (long long)w * 4) {
	    if ((long long)p * 4 > (long long)w * 5) {
		p *= 2;

		continue;
	    }

	    x = w;
	} else {
	    x = (long long)p * 5 / 4;
	}

	if (x * p > max) {
	    max = x * p;
	    a = p;
	    b = x;
	}

	p *= 2;
    }

    p = 1;

    while (p <= w) {
	if ((long long)p * 5 > (long long)h * 4) {
	    if ((long long)p * 4 > (long long)h * 5) {
		p *= 2;

		continue;
	    }

	    x = h;
	} else {
	    x = (long long)p * 5 / 4;
	}

	if (x * p > max || (x * p == max && x > a)) {
	    max = x * p;
	    a = x;
	    b = p;
	}

	p *= 2;
    }

    printf("%d %d\n", a, b);

    return 0;
}