#include <stdio.h>
#include <string.h>
#define MAXL 105

int l;
char s[MAXL];

int main(void)
{
   int t;
   scanf("%d",&t);
   while(t--) {
      scanf("%s",s);
      l=strlen(s);
      if(l<=10) puts(s);
      else {
         printf("%c%d%c\n",s[0],l-2,s[l-1]);
      }
   }
   return 0;
}