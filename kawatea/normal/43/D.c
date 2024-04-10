#include <stdio.h>

int main()
{
     int n, m, i, j;

     scanf("%d %d", &n, &m);

     if (n == 1 && m > 2) {
	  puts("1");
	  printf("1 %d 1 1\n", m);

	  for (i = 0; i < m; i++) printf("1 %d\n", i + 1);

	  puts("1 1");
     } else if (m == 1 && n > 2) {
	  puts("1");
	  printf("%d 1 1 1\n", n);

	  for (i = 0; i < n; i++) printf("%d 1\n", i + 1);

	  puts("1 1");
     } else if (n % 2 == 0) {
	  puts("0");
	  puts("1 1");

	  for (i = 0; i < n; i++) {
	       if (i % 2 == 0) {
		    for (j = 1; j < m; j++) {
			 printf("%d %d\n", i + 1, j + 1);
		    }
	       } else {
		    for (j = m - 1; j >= 1; j--) {
			 printf("%d %d\n", i + 1, j + 1);
		    }
	       }
	  }

	  for (i = n; i > 0; i--) printf("%d 1\n", i);
     } else {
	  if (m % 2 == 0) {
	       puts("0");
	       puts("1 1");

	       for (i = 0; i < m; i++) {
		    if (i % 2 == 0) {
			 for (j = 1; j < n; j++) {
			      printf("%d %d\n", j + 1, i + 1);
			 }
		    } else {
			 for (j = n - 1; j >= 1; j--) {
			      printf("%d %d\n", j + 1, i + 1);
			 }
		    }
	       }

	       for (i = m; i > 0; i--) printf("1 %d\n", i);
	  } else {
	       puts("1");
	       printf("%d %d 1 1\n", n, m);

	       for (i = 0; i < n; i++) {
		    if (i % 2 == 0) {
			 for (j = 0; j < m; j++) {
			      printf("%d %d\n", i + 1, j + 1);
			 }
		    } else {
			 for (j = m - 1; j >= 0; j--) {
			      printf("%d %d\n", i + 1, j + 1);
			 }
		    }
	       }

	       puts("1 1");
	  }
     }

     return 0;
}