#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
} event;

int cmp(const void *a, const void *b)
{
    return ((event *)a)->a - ((event *)b)->a;
}

int main()
{
    int n, c = 0, p, i;
    event e[100000];

    scanf("%d", &n);

    for (i = 0; i < n; i++) scanf("%d %d", &e[i].a, &e[i].b);

    qsort(e, n, sizeof(event), cmp);

    p = e[0].b;

    for (i = 1; i < n; i++) {
	if (e[i].b < p) {
	    c++;
	} else {
	    p = e[i].b;
	}
    }

    printf("%d\n", c);

    return 0;
}