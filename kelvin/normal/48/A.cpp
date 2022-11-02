#include <stdio.h>

inline int ges(const char *a) {
   if(a[0]=='r') return 0;
   if(a[0]=='p') return 1;
   if(a[0]=='s') return 2;
   return -1;
}

inline int win(int a,int b) {
   return (b+1)%3==a;
}

int main(void)
{
   char f[10],m[10],s[10];
   int gf,gm,gs;
   scanf("%s%s%s",f,m,s);
   gf=ges(f);
   gm=ges(m);
   gs=ges(s);
   if(win(gf,gm)&&win(gf,gs)) puts("F");
   else if(win(gm,gf)&&win(gm,gs)) puts("M");
   else if(win(gs,gf)&&win(gs,gm)) puts("S");
   else puts("?");
   return 0;
}