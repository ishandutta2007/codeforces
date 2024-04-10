#include <stdio.h>

int gcd(int a, int b)
{
    if (a % b == 0) return b;

    return gcd(b, a % b);
}

int main()
{
    int a, b, g, f = 0;
    long long l, c, d;

    scanf("%d %d", &a, &b);

    if (a < b) {
	int tmp = a; a = b; b = tmp;
	f = 1;
    }

    g = gcd(a, b);

    l = (long long)a / g * b;

    c = (long long)b * (b / g + 1) / 2;
    d = l - c;

    if (c == d) {
	puts("Equal");
    } else if ((c > d && f == 0) || (c < d && f == 1)) {
	puts("Dasha");
    } else {
	puts("Masha");
    }

    return 0;
}