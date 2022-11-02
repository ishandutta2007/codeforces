#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAXL 1050

using namespace std;

int rn,cn,bn,mod;
vector<int> ra[MAXL],ca[MAXL];

inline int power(int x,int p) {
   int s=1,m=x;
   while(p) {
      if(p&1) s=(long long)s*m%mod;
      m=(long long)m*m%mod;
      p>>=1;
   }
   return s;
}

#define FAIL { puts("0"); return 0; }

int main(void)
{
   scanf("%d %d %d",&rn,&cn,&bn);
   if(rn+cn&1) FAIL;
   for(int i=0;i<bn;i++) {
      int r,c,x;
      scanf("%d %d %d",&r,&c,&x);
      ra[r].push_back(x);
      ca[c].push_back(x);
   }
   scanf("%d",&mod);
   for(int i=1;i<=rn;i++) {
      if(ra[i].size()==cn) {
         int m=1;
         for(int j=0;j<ra[i].size();j++)
            m*=ra[i][j];
         if(m!=-1) FAIL;
         bn--;
      }
   }
   for(int i=1;i<=cn;i++) {
      if(ca[i].size()==rn) {
         int m=1;
         for(int j=0;j<ca[i].size();j++)
            m*=ca[i][j];
         if(m!=-1) FAIL;
         bn--;
      }
   }
   printf("%d\n",power(2,(rn-1)*(cn-1)-bn));
   return 0;
}