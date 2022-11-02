#include <stdio.h>
#include <string.h>
#define MAXN 105
#define MAXL 105

int fn,sl;
char s[MAXL],re,ne;
char fb[MAXN][MAXL];
int fl[MAXN];
bool cover[MAXL];

inline char lower(char c) {
//   printf("<%c>",c);
   if(c>='a'&&c<='z') return c;
   else return c-'A'+'a';
}
inline char upper(char c) {
   if(c>='A'&&c<='Z') return c;
   else return c-'a'+'A';
}
inline bool cmp(char *a,char *b) {
   int i;
//   puts(a);
//   puts(b);
   for(i=0;a[i]&&b[i];i++)
      if(lower(a[i])!=lower(b[i])) return 1;
   return 0;
}

inline void solve() {
   int i,j,k;
   for(i=0;s[i];i++)
      cover[i]=0;
   for(i=0;s[i];i++) {
      for(j=0;j<fn;j++) {
         if(i+fl[j]>sl) continue;
         if(!cmp(s+i,fb[j])) {//puts("!");
            for(k=0;k<fl[j];k++)
               cover[i+k]=1;
         }
      }
   }
   for(i=0;s[i];i++) {
      if(!cover[i]) continue;
//      printf("<%d>",i);
      if(lower(s[i])==lower(re)) {
         if(s[i]>='a'&&s[i]<='z') s[i]=lower(ne);
         else s[i]=upper(ne);
      }
      else {
         if(s[i]>='a'&&s[i]<='z') s[i]=lower(re);
         else s[i]=upper(re);
      }
   }
   puts(s);
}

int main(void)
{
   int i;
   char in[10];
   scanf("%d",&fn);
   for(i=0;i<fn;i++) {
      scanf("%s",fb[i]);
      fl[i]=strlen(fb[i]);
   }
   scanf("%s",s);
   sl=strlen(s);
   scanf("%s",in);
   re=in[0];
   if(re=='a') ne='b';
   else ne='a';
   solve();
   return 0;
}