#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char s[10001];
} answer;

int cmp(const void *a, const void *b)
{
    return strcmp(((answer *)a)->s, ((answer *)b)->s);
}

int main()
{
    int n, k, minimum = 1e9, p = 0, i, j;
    char s[10001];
    int a[10] = {0};
    int b[10];
    answer ans[10];

    scanf("%d %d", &n, &k);
    scanf("%s", s);

    for (i = 0; i < n; i++) a[s[i] - '0']++;

    for (i = 0; i < 10; i++) {
	if (a[i] >= k) {
	    puts("0");
	    printf("%s\n", s);

	    return 0;
	}
    }

    for (i = 0; i < 10; i++) {
	int c = 0, m = 0;

	c += a[i];

	for (j = 1; j < 10; j++) {
	    if (i + j <= 9) {
		if (c + a[i + j] < k) {
		    c += a[i + j];
		    m += j * a[i + j];
		} else {
		    m += j * (k - c);

		    break;
		}
	    }

	    if (i - j >= 0) {
		if (c + a[i - j] < k) {
		    c += a[i - j];
		    m += j * a[i - j];
		} else {
		    m += j * (k - c);
		    
		    break;
		}
	    }
	}

	if (m < minimum) {
	    minimum = m;
	    b[0] = i;
	    p = 1;
	} else if (m == minimum) {
	    b[p++] = i;
	}
    }

    printf("%d\n", minimum);

    for (i = 0; i < p; i++) {
	int c = 0, num = b[i];
	int f[10] = {0};
	int d[10];

	for (j = 0; j < 10; j++) d[j] = a[j];

	c += d[num];

	for (j = 1; j < 10; j++) {
	    if (num + j <= 9) {
		if (c + d[num + j] < k) {
		    c += d[num + j];
		    f[num + j] = d[num + j];
		} else {
		    f[num + j] = k - c;

		    break;
		}
	    }

	    if (num - j >= 0) {
		if (c + d[num - j] < k) {
		    c += d[num - j];
		    f[num - j] = d[num - j];
		} else {
		    f[num - j] = k - c;

		    break;
		}
	    }
	}

	for (j = 0; j < n; j++) {
	    if (f[s[j] - '0'] > 0) {
		if (s[j] - '0' > num || f[s[j] - '0'] == d[s[j] - '0']) {
		    ans[i].s[j] = num + '0';
		    f[s[j] - '0']--;
		    d[s[j] - '0']--;
		} else {
		    ans[i].s[j] = s[j];
		    d[s[j] - '0']--;
		}
	    } else {
		ans[i].s[j] = s[j];
	    }
	}

	ans[i].s[n] = '\0';
    }

    qsort(ans, p, sizeof(answer), cmp);

    printf("%s\n", ans[0].s);

    return 0;
}