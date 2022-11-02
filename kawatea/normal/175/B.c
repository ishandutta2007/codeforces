#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char s[11];
	int x;
	int y;
} player;

int cmp(const void *a, const void *b)
{
	return ((player *)a)->y - ((player *)b)->y;
}

int main()
{
	int n, m = 0, x, i, j;
	char s[11];
	player a[1000];

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%s %d", s, &x);

		for (j = 0; j < m; j++) {
			if (strcmp(a[j].s, s) == 0) break;
		}

		if (j == m) {
			strcpy(a[m].s, s);

			a[m++].x = x;
		} else if (a[j].x < x) {
			a[j].x = x;
		}
	}

	for (i = 0; i < m; i++) {
		int r = 0;

		for (j = 0; j < m; j++) {
			if (a[j].x > a[i].x) r++;
		}

		if (2 * r > m) {
			a[i].y = 0;
		} else if (5 * r > m) {
			a[i].y = 1;
		} else if (10 * r > m) {
			a[i].y = 2;
		} else if (100 * r > m) {
			a[i].y = 3;
		} else {
			a[i].y = 4;
		}
	}

	qsort(a, m, sizeof(player), cmp);

	printf("%d\n", m);

	for (i = 0; i < m; i++) {
		if (a[i].y == 0) {
			printf("%s noob\n", a[i].s);
		} else if (a[i].y == 1) {
			printf("%s random\n", a[i].s);
		} else if (a[i].y == 2) {
			printf("%s average\n", a[i].s);
		} else if (a[i].y == 3) {
			printf("%s hardcore\n", a[i].s);
		} else {
			printf("%s pro\n", a[i].s);
		}
	}

	return 0;
}