#include <stdio.h>

int main()
{
     int n, i;
     int a[100000];

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     for (i = 1; i < n; i++) {
	  if (a[i] != a[0]) break;
     }

     if (i == n) {
	  puts("0");

	  return 0;
     }

     if (a[i] > a[0]) {
	  int max = a[i], num = i;

	  for (i++; i < n; i++) {
	       if (a[i] >= max) {
		    max = a[i];
		    num = i;
	       } else {
		    puts("3");
		    printf("1 %d %d\n", num + 1, i + 1);

		    return 0;
	       }
	  }
     } else {
	  int min = a[i], num = i;

	  for (i++; i < n; i++) {
	       if (a[i] <= min) {
		    min = a[i];
		    num = i;
	       } else {
		    puts("3");
		    printf("1 %d %d\n", num + 1, i + 1);

		    return 0;
	       }
	  }
     }

     puts("0");

     return 0;
}