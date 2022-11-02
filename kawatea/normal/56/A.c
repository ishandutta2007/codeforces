#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
     int n, a = 0, i, j;
     char s[105];
     char c[11][10] = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
      scanf("%s", s);

      if (s[0] >= '0' && s[0] <= '9') {
           int x = atoi(s);

           if (x < 18) a++;
      } else {
           for (j = 0; j < 11; j++) {
            if (strcmp(s, c[j]) == 0) {
             a++;

             break;
            }
           }
      }
     }

     printf("%d\n", a);

     return 0;
}