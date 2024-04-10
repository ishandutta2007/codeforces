#include <stdio.h>
#include <string.h>

int main()
{
     int k, i;
     char s[10];
     char c[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

     scanf("%s %d", s, &k);

     for (i = 0; i < 12; i++) {
	  if (strcmp(s, c[i]) == 0) break;
     }

     i = (i + k) % 12;

     printf("%s\n", c[i]);

     return 0;
}