#include <stdio.h>

int main()
{
     int n = 0, l = 0, i;
     char s[105];

     while (fgets(s, 105, stdin) != NULL) {
      if (s[0] == '+') {
           n++;
      } else if (s[0] == '-') {
           n--;
      } else {
           for (i = 0; i < strlen(s); i++) {
            if (s[i] == ':') break;
           }

           l += (strlen(s) - i - 2) * n;
      }
     }

     printf("%d\n", l);

     return 0;
}