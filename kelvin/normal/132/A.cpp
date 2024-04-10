#include <stdio.h>
#include <string.h>
#define MAXL 200

int l;
char str[MAXL];

inline int rev(int x) {
   int s=0;
   for(int i=0;i<8;i++) {
      s=(s<<1)+(x&1);
      x>>=1;
   }
   return s;
}

int main(void)
{
   int p=0,r;
   gets(str);
   l=strlen(str);
   for(int i=0;i<l;i++) {
      r=(256+rev(p)-rev(str[i]))&255;
      printf("%d\n",r);
      p=str[i];
   }
   return 0;
}