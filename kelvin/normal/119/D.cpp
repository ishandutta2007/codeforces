#include <stdio.h>
#include <string.h>
#define MAXL 2000500

int sl,pl;
char s[MAXL],r[MAXL],p[MAXL];

char zs[MAXL];
int z[MAXL];

int pre[MAXL],match[MAXL];

int se[MAXL],me[MAXL],maxi;

inline int min(int a,int b) { return a<b?a:b; }
inline int max(int a,int b) { return a>b?a:b; }

inline void zvalue(char *s,int len) {
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

inline void prekmp(char *p,int pl) {
  int i,x;
  x=-1; // match to which position
  pre[0]=-1;
  for(i=1;i<pl;i++) {
    while(x>=0&&p[x+1]!=p[i])
      x=pre[x];
    if(p[x+1]==p[i]) x++;
    pre[i]=x;
  }
}

inline void matchkmp(char *s,int sl,char *p,int pl) {
  int i,x;
  x=-1; // match to which position
  for(i=0;i<sl;i++) {
    while(x>=0&&p[x+1]!=s[i])
      x=pre[x];
    if(p[x+1]==s[i]) x++;
    match[i]=x+1;
    if(match[i]==pl) x=pre[x];
  }
}

inline void precalc() {
   int i;
   for(i=0;i<sl;i++)
      r[i]=s[sl-i-1];
   // se
   strcpy(zs,p);
   strcpy(zs+pl,s);
   zvalue(zs,pl+sl);
   for(i=0;i<sl;i++)
      se[i]=z[i+pl];
   // oki
   prekmp(r,sl);
   matchkmp(p,pl,r,sl);
   for(i=0;i<sl;i++)
      me[i]=match[sl-i-1];
   // maxi
   for(i=0;i<sl-1;i++)
      if(p[pl-i-1]!=s[i]) break;
   maxi=i-1;
}

inline void solve() {
   sl=strlen(s);
   pl=strlen(p);
   if(sl!=pl) {
      puts("-1 -1");
      return;
   }
   precalc();
   /*for(int i=0;i<sl;i++)
      printf("%d ",se[i]);puts("");
   for(int i=0;i<sl;i++)
      printf("%d ",me[i]);puts("");
   printf("<%d>\n",maxi);*/
   for(int i=maxi;i>=0;i--) {
      if(i+se[i+1]>=sl-me[i+1]-1) {
         int j=sl-me[i+1];
         printf("%d %d\n",i,j);
         return;
      }
   }
   puts("-1 -1");
   return;
}

int main(void)
{
   gets(s);
   gets(p);
   solve();
   return 0;
}