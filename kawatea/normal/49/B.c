#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
     int a, b, num = 0, i, j;
     int p[10] = {0};
     char s1[5], s2[5];

     scanf("%s %s", s1, s2);

     a = atoi(s1); b = atoi(s2);

     while (a) {
	  p[a % 10]++;
	  a /= 10;
     }

     while (b) {
	  p[b % 10]++;
	  b /= 10;
     }

     for (i = 9; i > 0; i--) {
	  if (p[i] > 0) break;
     }

     for (j = 0; j < strlen(s1); j++) {
	  a *= (i + 1);
	  a += s1[j] - '0';
     }

     for (j = 0; j < strlen(s2); j++) {
	  b *= (i + 1);
	  b += s2[j] - '0';
     }

     a += b;

     while (a) {
	  a /= (i + 1);
	  num++;
     }

     printf("%d\n", num);

     return 0;
}