#include <stdio.h>
#include <stdlib.h>

int cmp_perm(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

int next_permutation(int a[], int n)
{
    int m = a[n - 1], p = 1, i, j;
    int b[20];

    b[0] = m;

    for (i = n - 2; i >= 0; i--) {
	if (m > a[i]) {
	    qsort(b, p, sizeof(int), cmp_perm);

	    for (j = 0; ; j++) {
		if (b[j] > a[i]) {
		    m = a[i];
		    a[i++] = b[j];
		    b[j] = m;

		    break;
		}
	    }

	    for (p = 0; i < n; i++) {
		a[i] = b[p++];
	    }

	    return 1;
	} else {
	    b[p++] = a[i];

	    if (a[i] > m) m = a[i];
	}
    }

    return 0;
}

int main()
{
     int r1, r2, c1, c2, d1, d2;
     int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

     scanf("%d %d", &r1, &r2);
     scanf("%d %d", &c1, &c2);
     scanf("%d %d", &d1, &d2);

     do {
	  if (a[0] + a[1] != r1) continue;
	  if (a[2] + a[3] != r2) continue;
	  if (a[0] + a[2] != c1) continue;
	  if (a[1] + a[3] != c2) continue;
	  if (a[0] + a[3] != d1) continue;
	  if (a[1] + a[2] != d2) continue;

	  printf("%d %d\n", a[0], a[1]);
	  printf("%d %d\n", a[2], a[3]);

	  return 0;
     } while (next_permutation(a, 9));

     puts("-1");

     return 0;
}