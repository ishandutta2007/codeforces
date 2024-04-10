#include <stdio.h>
#include <stdlib.h>

int main()
{
     int t, n, i;
     FILE *fp1, *fp2;

     fp1 = fopen("input.txt", "r");
     fp2 = fopen("output.txt", "w");

     fscanf(fp1, "%d", &t);

     for (i = 0; i < t; i++) {
	  fscanf(fp1, "%d", &n);

	  if (n % 2 == 1) {
	       fprintf(fp2, "0\n");
	  } else {
	       fprintf(fp2, "1\n");
	  }
     }

     fclose(fp1);
     fclose(fp2);

     return 0;
}