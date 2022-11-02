#include <stdio.h>
#include <string.h>
#define MAXL 100050

int n,h;
char s[MAXL];
//int next8[MAXL],next7[MAXL],next5[MAXL],next4[MAXL],next3[MAXL];
int nextnot7[MAXL],nextnot4[MAXL];

inline void pre() {
   int i;
//   next8[n]=next7[n]=next5[n]=next4[n]=next3[n]=n;
   nextnot7[n]=nextnot4[n]=n;
   for(i=n-1;i>=0;i--) {
      nextnot7[i]=nextnot7[i+1];
      nextnot4[i]=nextnot4[i+1];
//      next8[i]=next8[i+1];
//      next7[i]=next7[i+1];
//      next5[i]=next5[i+1];
//      next4[i]=next4[i+1];
//      next3[i]=next3[i+1];
      if(s[i]!='7') nextnot7[i]=i;
      if(s[i]!='4') nextnot4[i]=i;
//      if(s[i]>'7') next8[i]=i;
//      else if(s[i]=='7') next7[i]=i;
//      else if(s[i]>'4') next5[i]=i;
//      else if(s[i]=='4') next4[i]=i;
//      else next3[i]=i;
   }
}

inline bool toobig() {
   int i;
   for(i=0;i<h;i++) {
      if(s[i]<'7') return 0;
      if(s[i]>'7') return 1;
   }
   for(i=h;i<n;i++) {
      if(s[i]<'4') return 0;
      if(s[i]>'4') return 1;
   }
   return 0;
}

inline void solve() {
   int i,r4,r7;
   h=(n+1)/2;
   if(n&1) {
      for(i=0;i<h;i++)
         printf("4");
      for(i=0;i<h;i++)
         printf("7");
      puts("");
      return;
   }
   if(toobig()) {
      for(i=0;i<h+1;i++)
         printf("4");
      for(i=0;i<h+1;i++)
         printf("7");
      puts("");
      return;
   }
   pre();
   r4=r7=h;
   for(i=0;i<n;i++) {
      if(s[i]<'4'&&r4) {
         printf("4");
         r4--;
         break;
      }
      if(s[i]=='4'&&r4) {
         // from i+1: r7*7,r4*4
         r4--;
//         printf("<%s %d %d %d>\n",s,i,r7,r4);
         int x=nextnot7[i+1];
         if(x<=i+r7) {
            if(s[x]<'7') goto good;
            else goto bad;
         }
         x=nextnot4[i+r7+1];
         if(s[x]<'4') goto good;
         else goto bad;
good:
         printf("4");
         continue;
bad:
         r4++;
      }
      printf("7");
      r7--;
      if(s[i]<'7') break;
   }
   while(r4--)
      printf("4");
   while(r7--)
      printf("7");
   puts("");
}

int main(void)
{
   while(scanf("%s",s)!=EOF) {
      n=strlen(s);
      solve();
   }
   return 0;
}