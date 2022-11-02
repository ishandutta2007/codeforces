#include <stdio.h>
#include <string.h>

int a[5000001], b[5000002], c[5000002];
int n;

int hash1(int x, int y)
{
    return (b[x + y] - b[x]) * a[n - x - 1];
}

int hash2(int x, int y)
{
    return (c[x + y] - c[x]) * a[n - x - 1];
}

int main()
{
    int sum = 0, i;
    char s[5000001];

    scanf("%s", s);

    n = strlen(s);

    a[0] = 1;

    for (i = 1; i < n; i++) a[i] = a[i - 1] * 1007;

    for (i = 0; i < n; i++) {
	if (s[i] >= 'a' && s[i] <= 'z') {
	    b[i + 1] = b[i] + (s[i] - 'a' + 1) * a[i];
	} else if (s[i] >= 'A' && s[i] <= 'Z') {
	    b[i + 1] = b[i] + (s[i] - 'A' + 27) * a[i];
	} else {
	    b[i + 1] = b[i] + (s[i] - '0' + 53) * a[i];
	}

	if (s[n - i - 1] >= 'a' && s[n - i - 1] <= 'z') {
	    c[i + 1] = c[i] + (s[n - i - 1] - 'a' + 1) * a[i];
	} else if (s[n - i - 1] >= 'A' && s[n - i - 1] <= 'Z') {
	    c[i + 1] = c[i] + (s[n - i - 1] - 'A' + 27) * a[i];
	} else {
	    c[i + 1] = c[i] + (s[n - i - 1] - '0' + 53) * a[i];
	}
    }

    for (i = n; i > 0; i--) {
	int k = 0, m = i;

	while (hash1(0, m) == hash2(n - m, m) && m > 0) {
	    k++;
	    m /= 2;
	}

	sum += k;
    }

    printf("%d\n", sum);

    return 0;
}