#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
     char s[260], c[1000];
     int n, p = 0, f = 0, i;

     fgets(s, 260, stdin);

     n = strlen(s);

     s[--n] = '\0';

     for (i = 0; i < n; i++) {
          if (s[i] == ',') {
               c[p++] = ',';
               c[p++] = ' ';
          } else if (s[i] == '.') {
               if (f % 3 == 0 && p > 0 && c[p - 1] != ' ') {
                    c[p++] = ' ';
                    c[p++] = '.';
               } else {
                    c[p++] = '.';
               }
               f++;
          } else if (isdigit(s[i])) {
               if (i > 0 && p > 0 && !isdigit(s[i - 1]) && isdigit(c[p - 1])) {
                    c[p++] = ' ';
               }
               c[p++] = s[i];
          }
     }

     if (c[p - 1] == ' ') p--;

     c[p] = '\0';

     printf("%s\n", c);

     return 0;
}