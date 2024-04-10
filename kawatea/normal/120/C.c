#include <stdio.h>
#include <stdlib.h>

int main()
{
     int n, k, sum = 0, i;
     int a[100];
     FILE *fp1, *fp2;

     fp1 = fopen("input.txt", "r");
     fp2 = fopen("output.txt", "w");

     fscanf(fp1, "%d %d", &n, &k);

     for (i = 0; i < n; i++) fscanf(fp1, "%d", &a[i]);

     for (i = 0; i < n; i++) {
	  if (a[i] / k >= 3) {
	       sum += a[i] - k * 3;
	  } else {
	       sum += a[i] % k;
	  }
     }

     fprintf(fp2, "%d\n", sum);

     fclose(fp1);
     fclose(fp2);

     return 0;
}