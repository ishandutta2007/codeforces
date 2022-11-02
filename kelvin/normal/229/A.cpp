#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#define MAXR 105
#define MAXC 10050

using namespace std;

int rn,cn;
char gr[MAXR][MAXC];
int lm[MAXR][MAXC],rm[MAXR][MAXC];

inline int mod(int x,int m) {
   if(x<0) x+=m;
   if(x>=m) x-=m;
   return x;
}

int solve() {
   for(int i=0;i<rn;i++) {
      bool f=0;
      for(int j=0;j<cn;j++)
         if(gr[i][j]=='1') f=1;
      if(!f) return -1;
   }
   for(int i=0;i<rn;i++) {
      for(int j=0;j<cn;j++) {
         if(gr[i][j]=='1') lm[i][j]=rm[i][j]=0;
         else lm[i][j]=rm[i][j]=cn;
      }
      for(int t=0;t<2;t++)
         for(int j=0;j<cn;j++)
            lm[i][j]=min(lm[i][j],lm[i][mod(j-1,cn)]+1);
      for(int t=0;t<2;t++)
         for(int j=cn-1;j>=0;j--)
            rm[i][j]=min(rm[i][j],rm[i][mod(j+1,cn)]+1);
   }
   int ret=rn*cn;
   for(int j=0;j<cn;j++) {
      int s=0;
      for(int i=0;i<rn;i++)
         s+=min(lm[i][j],rm[i][j]);
      ret=min(ret,s);
   }
   return ret;
}

int main(void)
{
   scanf("%d %d",&rn,&cn);
   for(int i=0;i<rn;i++)
      scanf("%s",gr[i]);
   printf("%d\n",solve());
   return 0;
}