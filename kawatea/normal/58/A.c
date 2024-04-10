#include <stdio.h>
#include <string.h>

int main()
{
     char s[105];
     char c[6] = "hello";
     int n = 0, i;

     scanf("%s", s);

     for (i = 0; i < strlen(s); i++) {
      if (s[i] == c[n]) {
           n++;

           if (n == 5) {
            puts("YES");

            return 0;
           }
      }
     }

     puts("NO");

     return 0;
}