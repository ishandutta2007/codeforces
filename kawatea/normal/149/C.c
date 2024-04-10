#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int a;
     int f;
     int i;
} boy;

int cmp(const void *a, const void *b)
{
     return ((boy *)b)->a - ((boy *)a)->a;
}

int main()
{
     int n, x = 0, y = 0, p = 0, q = 0, i;
     boy b[100000];

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%d", &b[i].a);

	  b[i].f = 0;
	  b[i].i = i + 1;
     }

     qsort(b, n, sizeof(boy), cmp);

     for (i = 0; i < n; i += 4) {
	  if (n - i >= 4) {
	       int c = b[i].a + b[i + 3].a;
	       int d = b[i + 1].a + b[i + 2].a;

	       if ((p < q && c > d) || (p > q && c < d)) {
		    p += c;
		    q += d;

		    b[i].f = b[i + 3].f = 1;
		    b[i + 1].f = b[i + 2].f = 2;
	       } else {
		    p += d;
		    q += c;

		    b[i].f = b[i + 3].f = 2;
		    b[i + 1].f = b[i + 2].f = 1;
	       }

	       x += 2;
	       y += 2;
	  } else if (n - i == 3) {
	       int c = b[i].a;
	       int d = b[i + 1].a + b[i + 2].a;

	       if ((p < q && c > d) || (p > q && c < d)) {
		    p += c;
		    q += d;

		    b[i].f = 1;
		    b[i + 1].f = b[i + 2].f = 2;

		    x++;
		    y += 2;
	       } else {
		    p += d;
		    q += c;

		    b[i].f = 2;
		    b[i + 1].f = b[i + 2].f = 1;

		    x += 2;
		    y++;
	       }
	  } else if (n - i == 2) {
	       if (p < q) {
		    b[i].f = 1;
		    b[i + 1].f = 2;
	       } else {
		    b[i].f = 2;
		    b[i + 1].f = 1;
	       }

	       x++;
	       y++;
	  } else {
	       if (p < q) {
		    b[i].f = 1;

		    x++;
	       } else {
		    b[i].f = 2;

		    y++;
	       }
	  }
     }	       

     printf("%d\n", x);

     for (i = 0; i < n; i++) {
	  if (b[i].f == 1) {
	       printf("%d ", b[i].i);
	  }
     }

     puts("");

     printf("%d\n", y);

     for (i = 0; i < n; i++) {
	  if (b[i].f == 2) {
	       printf("%d ", b[i].i);
	  }
     }

     puts("");

     return 0;
}