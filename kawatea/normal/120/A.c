#include <stdio.h>
#include <stdlib.h>

int main()
{
     char s[10];
     int a;
     FILE *fp1, *fp2;

     fp1 = fopen("input.txt", "r");
     fp2 = fopen("output.txt", "w");

     fscanf(fp1, "%s %d", s, &a);

     if ((s[0] == 'f' && a == 1) || (s[0] == 'b' && a == 2)) {
	  fprintf(fp2, "L\n");
     } else {
	  fprintf(fp2, "R\n");
     }

     fclose(fp1);
     fclose(fp2);

     return 0;
}