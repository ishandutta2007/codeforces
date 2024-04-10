#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int a;
    int i;
} score;

int v[200001], c[200001];
score s1[200001], s2[200001];

int cmp(const void *a, const void *b)
{
    return ((score *)a)->a - ((score *)b)->a;
}

int main()
{
    int n, i, j;
    char s[200001];
    char a[10] = {"aeiouAEIOU"};

    scanf("%s", s);

    n = strlen(s);

    for (i = 0; i < n; i++) {
	for (j = 0; j < 10; j++) {
	    if (s[i] == a[j]) break;
	}

	if (j < 10) {
	    v[i + 1] = v[i] + 1;
	    c[i + 1] = c[i];
	} else {
	    v[i + 1] = v[i];
	    c[i + 1] = c[i] + 1;
	}
    }

    for (i = 0; i <= n; i++) {
	s1[i].a = 2 * c[i] - v[i];
	s2[i].a = -s1[i].a;
	s1[i].i = s2[i].i = i;
    }

    if (c[n] == 0) {
	puts("No solution");
    } else {
	int m = 0, num = 0, p, q;

	qsort(s1, n + 1, sizeof(score), cmp);
	qsort(s2, n + 1, sizeof(score), cmp);

	p = n;
	q = s1[n].i;

	for (i = 0; i <= n; i++) {
	    for (; p >= 0; p--) {
		if (s1[p].a + s2[i].a < 0) break;

		if (s1[p].i > q) q = s1[p].i;
	    }

	    if (q - s2[i].i > m) {
		m = q - s2[i].i;
		num = 1;
	    } else if (q - s2[i].i == m) {
		num++;
	    }
	}

	printf("%d %d\n", m, num);
    }

    return 0;
}