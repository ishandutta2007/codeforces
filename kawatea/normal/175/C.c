#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int k;
	int c;
} figure;

int cmp(const void *a, const void *b)
{
	return ((figure *)a)->c - ((figure *)b)->c;
}

int main()
{
	int n, t, i, j;
	long long sum = 0, f = 1, x = 0;
	figure a[100];
	long long p[100];

	scanf("%d", &n);

	for (i = 0; i < n; i++) scanf("%d %d", &a[i].k, &a[i].c);

	scanf("%d", &t);

	for (i = 0; i < t; i++) scanf("%I64d", &p[i]);

	qsort(a, n, sizeof(figure), cmp);

	for (i = 0; i < t; i++) {
		for (j = 0; j < n; j++) {
			if (x + a[j].k < p[i]) {
				sum += f * a[j].k * a[j].c;

				x += a[j].k;

				a[j].k = 0;
			} else {
				sum += f * (p[i] - x) * a[j].c;

				a[j].k -= p[i] - x;

				x = p[i];

				break;
			}
		}

		f++;
	}

	for (i = 0; i < n; i++) {
		if (a[i].k > 0) sum += f * a[i].k * a[i].c;
	}

	printf("%I64d\n", sum);

	return 0;
}