#include <stdio.h>
#define MAXL 105

char s[MAXL];
char z[6]="hello";

int main(void)
{
   scanf("%s",s);
   int p=0;
   for(int i=0;s[i];i++)
      if(p<5&&s[i]==z[p]) p++;
   puts(p==5?"YES":"NO");
   return 0;
}