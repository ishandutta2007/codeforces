#include <stdio.h>
#include <string.h>

int main()
{
     char s[101];
     int i, j, k;

     scanf("%s", s);

     for (i = strlen(s) - 1; i > 0; i--) {
      for (j = 0; j + i < strlen(s); j++) {
           char c[101];

           strncpy(c, &s[j], i);

           for (k = j + 1; k + i <= strlen(s); k++) {
            if (strncmp(c, &s[k], i) == 0) {
             printf("%d\n", i);

             return 0;
            }
           }
      }
     }

     puts("0");

     return 0;
}