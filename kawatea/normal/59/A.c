#include <stdio.h>
#include <string.h>

int main()
{
     char s[105];
     int a = 0, b = 0, i;

     scanf("%s", s);

     for (i = 0; i < strlen(s); i++) {
      if (s[i] >= 'A' && s[i] <= 'Z') {
           a++;
      } else {
           b++;
      }
     }

     for (i = 0; i < strlen(s); i++) {
      s[i] |= 32;

      if (a > b) s[i] ^= 32;
     }

     printf("%s\n", s);

     return 0;
}