#include <stdio.h>

char s[100000];

inline bool solve() {
   for(int i=0;s[i];i++)
      if(s[i]=='H'||s[i]=='Q'||s[i]=='9') return 1;
   return 0;
}

int main(void)
{
   gets(s);
   puts(solve()?"YES":"NO");
   return 0;
}