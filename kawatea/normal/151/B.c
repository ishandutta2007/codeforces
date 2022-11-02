#include <stdio.h>

typedef struct {
     char s[21];
     int a;
     int b;
     int c;
} friend;

int main()
{
     int n, max, f, i, j, k;
     friend a[100];

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  int c;

	  scanf("%d %s", &c, a[i].s);

	  a[i].a = a[i].b = a[i].c = 0;

	  for (j = 0; j < c; j++) {
	       char s[10];
	       int b[6];

	       scanf("%s", s);

	       for (k = 0; k < 6; k++) {
		    b[k] = s[k + k / 2];
	       }

	       for (k = 0; k < 5; k++) {
		    if (b[k] != b[k + 1]) break;
	       }

	       if (k == 5) {
		    a[i].a++;

		    continue;
	       }

	       for (k = 0; k < 5; k++) {
		    if (b[k] <= b[k + 1]) break;
	       }

	       if (k == 5) {
		    a[i].b++;
	       } else {
		    a[i].c++;
	       }
	  }
     }

     max = f = 0;

     for (i = 0; i < n; i++) {
	  if (a[i].a > max) max = a[i].a;
     }

     printf("If you want to call a taxi, you should call: ");

     for (i = 0; i < n; i++) {
	  if (a[i].a == max) {
	       if (f == 0) {
		    printf("%s", a[i].s);
	       } else {
		    printf(", %s", a[i].s);
	       }

	       f = 1;
	  }
     }

     puts(".");

     max = f = 0;

     for (i = 0; i < n; i++) {
	  if (a[i].b > max) max = a[i].b;
     }

     printf("If you want to order a pizza, you should call: ");

     for (i = 0; i < n; i++) {
	  if (a[i].b == max) {
	       if (f == 0) {
		    printf("%s", a[i].s);
	       } else {
		    printf(", %s", a[i].s);
	       }

	       f = 1;
	  }
     }

     puts(".");

     max = f = 0;

     for (i = 0; i < n; i++) {
	  if (a[i].c > max) max = a[i].c;
     }

     printf("If you want to go to a cafe with a wonderful girl, you should call: ");

     for (i = 0; i < n; i++) {
	  if (a[i].c == max) {
	       if (f == 0) {
		    printf("%s", a[i].s);
	       } else {
		    printf(", %s", a[i].s);
	       }

	       f = 1;
	  }
     }

     puts(".");

     return 0;
}