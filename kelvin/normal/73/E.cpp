#include <stdio.h>
#include <algorithm>
#define MAXN 2000050

int pn,pr[MAXN];
bool np[MAXN]={0};

int n;
int ln,ls[MAXN];

inline void gen() {
   pn=0;
   for(int i=2;i<MAXN;i++) {
      if(np[i]) continue;
      pr[pn++]=i;
      if(i>2000) continue;
      for(int j=i*i;j<MAXN;j+=i)
         np[j]=1;
   }
}

inline int solve() {
   int i,j,p,c=0;
   if(n==2) return 0;
   std::sort(ls,ls+ln);
   if(ln&&ls[0]==1) return 1;
   j=0;
   for(i=0;i<pn&&pr[i]<n;i++) {
      p=pr[i];
      while(j<ln&&ls[j]<p) j++;
      if(j>=ln||ls[j]!=p) return -1;
      c++;
   }
   return c;
}

int main(void)
{
   gen();
   while(scanf("%d %d",&ln,&n)==2) {
      for(int i=0;i<ln;i++)
         scanf("%d",ls+i);
      printf("%d\n",solve());
   }
   return 0;
}