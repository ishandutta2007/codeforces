#include <stdio.h>
#include <stdlib.h>

int main()
{
     int n, k, i;
     int a[1000];
     FILE *fp1, *fp2;

     fp1 = fopen("input.txt", "r");
     fp2 = fopen("output.txt", "w");

     fscanf(fp1, "%d %d", &n, &k);

     for (i = 0; i < n; i++) fscanf(fp1, "%d", &a[i]);

     for (i = k - 1; ;) {
	  if (a[i] == 1) break;

	  i = (i + 1) % n;
     }

     fprintf(fp2, "%d\n", i + 1);

     fclose(fp1);
     fclose(fp2);

     return 0;
}