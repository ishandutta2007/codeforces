#include <stdio.h>
#include <string.h>
#define MAXL 2000500

int len;
char s[MAXL];
int z[MAXL];

inline int min(int a,int b) { return a<b?a:b; }
inline int max(int a,int b) { return a>b?a:b; }

inline void z_value() {
   int i,j,left,right;
   left=right=0;
   z[0]=len;
   for(i=1;i<len;i++) {
      j=max(min(z[i-left],right-i),0);
      for(;i+j<len&&s[i+j]==s[j];j++);
      z[i]=j;
      if(i+z[i]>right) {
         right=i+z[i];
         left=i;
      }
   }
}

inline void solve() {
   int curmax,optl;
   if(len<=2) {
      puts("Just a legend");
      return;
   }
   z_value();
   //for(int i=0;i<len;i++)
   //   printf("%d,",z[i]);
   optl=0;
   curmax=z[1];
   for(int i=2;i<len;i++) {
      if(i+z[i]==len) {
         if(curmax>=z[i]) {
            if(z[i]>optl) {
               optl=z[i];
            }
         }
      }
      if(z[i]>curmax) curmax=z[i];
   }
   if(optl==0) {
      puts("Just a legend");
      return;
   }
   s[optl]='\0';
   puts(s);
}

int main(void)
{
   gets(s);
   len=strlen(s);
   solve();
   return 0;
}