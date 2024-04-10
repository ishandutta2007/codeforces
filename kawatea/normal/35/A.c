#include <stdio.h>

int main()
{
     int n, i;
     int a[3] = {0};
     FILE *fp1, *fp2;

     fp1 = fopen("input.txt", "r");
     fp2 = fopen("output.txt", "w");

     fscanf(fp1, "%d", &n);

     a[n - 1]++;

     for (i = 0; i < 3; i++) {
	  int x, y, tmp;

	  fscanf(fp1, "%d %d", &x, &y);

	  tmp = a[x - 1];
	  a[x - 1] = a[y - 1];
	  a[y - 1] = tmp;
     }

     for (i = 0; i < 3; i++) {
	  if (a[i] == 1) {
	       fprintf(fp2, "%d\n", i + 1);
	  }
     }

     fclose(fp1);
     fclose(fp2);

     return 0;
}