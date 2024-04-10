#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

const int inf=1000000010;

int n,m;

int gao(int c) { // c cols, m ones, how many people?
   int q=m;
   long long nn=0;
   long long cm=1,ccm=1;
   //printf("<%d>\n",c);
   for(int b=0;b<=c;b++) {
      long long maxr=b?(long long)q*c/b:inf;
      long long r=min(min(maxr,cm),(long long)inf);
      nn+=r;
      if(nn>inf||r<cm) break;
      if(b>0) {
         q-=ccm;
         ccm=ccm*(c-b)/b;
      }
      cm=cm*(c-b)/(b+1);
   }
   return min(nn,(long long)inf);
}

int solve() {
   if(m==1) return n-1;
   int l=-1,r=inf; // how many forms required
   while(l<r-1) {
      int mid=(l+r)>>1;
      int val=gao(mid);
      if(val>=n) r=mid;
      else l=mid;
   }
   return r;
}

int main(void)
{
   int t;
   scanf("%d",&t);
   while(t--) {
      scanf("%d %d",&n,&m);
      printf("%d\n",solve());
   }
   return 0;
}