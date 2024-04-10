#include <stdio.h>
#include <string.h>
#define MAXL 105

int sl,tl;
char s[MAXL];
char t[MAXL];

inline bool solve() {
   sl=strlen(s);
   tl=strlen(t);
   if(sl!=tl) return 0;
   for(int i=0;i<sl;i++)
      if(s[i]!=t[sl-i-1]) return 0;
   return 1;
}

int main(void)
{
   scanf("%s%s",s,t);
   puts(solve()?"YES":"NO");
   return 0;
}