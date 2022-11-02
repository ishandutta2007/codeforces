#include <stdio.h>
#define MAXL 106

char s[MAXL];

inline bool solve() {
   int c=0;
   for(int i=0;s[i];i++) {
      if(!i||s[i]==s[i-1]) c++;
      else c=1;
      if(c>=7) return 1;
   }
   return 0;
}

int main(void)
{
   scanf("%s",s);
   puts(solve()?"YES":"NO");
   return 0;
}