#include <stdio.h>
#include <string.h>

int a[1000001], b[1000002];
int n;

int hash(int x, int y)
{
    return (b[x + y] - b[x]) * a[n - x - 1];
}

int main()
{
    int max = 0, i;
    char s[1000001];

    scanf("%s", s);

    n = strlen(s);

    a[0] = 1;

    for (i = 1; i < n; i++) a[i] = a[i - 1] * 31;

    for (i = 0; i < n; i++) b[i + 1] = b[i] + (s[i] - 'a' + 1) * a[i];

    for (i = 1; i < n - 1; i++) {
	int l = 0, r = n - i, m = (l + r) / 2;

	while (r - l > 1) {
	    if (hash(0, m) == hash(i, m)) {
		l = m;
		m = (l + r) / 2;
	    } else {
		r = m;
		m = (l + r) / 2;
	    }
	}

	if (l > max) max = l;
    }

    for (i = max; i > 0; i--) {
	if (hash(0, i) == hash(n - i, i)) {
	    s[i] = '\0';

	    printf("%s\n", s);

	    return 0;
	}
    }

    puts("Just a legend");

    return 0;
}