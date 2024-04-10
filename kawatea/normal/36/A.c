#include <stdio.h>

int main()
{
     int n, f = 0, p = 0, i, j;
     int a[100];
     FILE *fp1, *fp2;

     fp1 = fopen("input.txt", "r");
     fp2 = fopen("output.txt", "w");

     fscanf(fp1, "%d", &n);

     for (i = 0; i < n; i++) fscanf(fp1, "%1d", &a[i]);

     for (i = 0; i < n; i++) {
	  if (a[i] == 1) {
	       if (f == 0) {
		    p = i;

		    f = 1;
	       } else {
		    p = i - p;

		    break;
	       }
	  }
     }

     for (i = 0; i < n; i++) {
	  if (a[i] == 1) {
	       for (j = i + 1; j < n; j++) {
		    if (a[j] == 1) break;
	       }

	       if (j < n && i + p != j) {
		    fprintf(fp2, "NO\n");

		    fclose(fp1);
		    fclose(fp2);

		    return 0;
	       }

	       i = j - 1;
	  }
     }

     fprintf(fp2, "YES\n");

     fclose(fp1);
     fclose(fp2);

     return 0;
}