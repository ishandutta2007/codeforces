#include <stdio.h>
#include <string.h>
#define MAXN 30050
#define MAXL 25

int n;
char s[MAXN][MAXL];
int sl[MAXN];

int main(void)
{
   scanf("%d",&n);
   for(int i=0;i<n;i++) {
      scanf("%s",s[i]);
      sl[i]=strlen(s[i]);
   }
   int x;
   for(x=0;;x++) {
      char c=s[0][x];
      for(int i=0;i<n;i++)
         if(x>=sl[i]||s[i][x]!=c) goto OUT;
   }
OUT:;
   printf("%d\n",x);
   return 0;
}