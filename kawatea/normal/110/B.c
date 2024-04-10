#include <stdio.h>

int main()
{
     int n, i;
     char s[4] = "abcd";

     scanf("%d", &n);

     for (i = 0; i < n; i++) printf("%c", s[i % 4]);
     puts("");

     return 0;
}