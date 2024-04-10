#include <stdio.h>
#define MAXL 155

int rn,cn,lastr;
char gr[MAXL][MAXL];
int lmost[MAXL],rmost[MAXL];

inline int max(int a,int b) { return a>b?a:b; }
inline int min(int a,int b) { return a<b?a:b; }
inline int abs(int x) { return x<0?-x:x; }

inline void pre() {
   int r,c;
   lastr=0;
   for(r=0;r<rn;r++) {
      lmost[r]=rn;
      for(c=cn-1;c>=0;c--) {
         if(gr[r][c]=='W') {
            lmost[r]=c;
            lastr=r;
         }
      }
      rmost[r]=-1;
      for(c=0;c<cn;c++) {
         if(gr[r][c]=='W') {
            rmost[r]=c;
            lastr=r;
         }
      }
   }
}

inline int solve() {
   int r,c=0,d=0,x;
   pre();
   for(r=0;r<rn;r++) {
      if(r&1) { // left
         x=c;
         if(rmost[r]>=0) x=min(x,lmost[r]);
         if(r<rn-1&&rmost[r+1]>=0) x=min(x,lmost[r+1]);
         d+=abs(c-x);
      } else { // right
         x=c;
         if(rmost[r]>=0) x=max(x,rmost[r]);
         if(r<rn-1&&rmost[r+1]>=0) x=max(x,rmost[r+1]);
         d+=abs(c-x);
      }
      c=x;
      if(r==lastr) break;
      d++;
   }
   return d;
}

int main(void)
{
   scanf("%d %d",&rn,&cn);
   for(int i=0;i<rn;i++)
      scanf("%s",gr[i]);
   printf("%d\n",solve());
   return 0;
}