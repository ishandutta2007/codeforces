#include <stdio.h>
#include <string.h>
#define MAXL 105

char a[MAXL],b[MAXL];

inline void lower(char *s) {
   for(int i=0;s[i];i++)
      if(s[i]>='A'&&s[i]<='Z') s[i]=s[i]-'A'+'a';
}

int main(void)
{
   scanf("%s%s",a,b);
   lower(a);
   lower(b);
   printf("%d\n",strcmp(a,b));
   return 0;
}