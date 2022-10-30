#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
     return *((int *)a) - *((int *)b);
}

int main()
{
     int n, x, i;
     int a[100];
     FILE *fp1, *fp2;

     fp1 = fopen("input.txt", "r");
     fp2 = fopen("output.txt", "w");

     fscanf(fp1, "%d %d", &n, &x);

     for (i = 0; i < n; i++) {
	  int p;

	  fscanf(fp1, "%d", &p);

	  a[i] = p * (n - i);
     }

     qsort(a, n, sizeof(int), cmp);

     for (i = 0; i < n; i++) {
	  if (x - a[i] >= 0) {
	       x -= a[i];
	  } else {
	       break;
	  }
     }

     fprintf(fp2, "%d\n", i);

     fclose(fp1);
     fclose(fp2);

     return 0;
}