#include <stdio.h>
#include <string.h>

int main()
{
     char s1[105], s2[105];
     int i;

     scanf("%s %s", s1, s2);

     for (i = 0; i < strlen(s1); i++) printf("%d", (s1[i] - '0') ^ (s2[i] - '0'));
     puts("");

     return 0;
}