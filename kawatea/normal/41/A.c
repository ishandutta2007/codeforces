#include <stdio.h>
#include <string.h>

int main()
{
     char s1[105], s2[105];
     int i;

     scanf("%s %s", s1, s2);

     if (strlen(s1) != strlen(s2)) {
      puts("NO");

      return 0;
     }

     for (i = 0; i < strlen(s1); i++) {
      if (s1[i] != s2[strlen(s1) - i - 1]) {
           puts("NO");

           return 0;
      }
     }

     puts("YES");

     return 0;
}