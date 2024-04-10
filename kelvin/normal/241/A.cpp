#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define MAXN 1050

using namespace std;

int n,k;
int d[MAXN],s[MAXN];

int solve() {
   int cur=0,best=0,t=0;
   for(int i=0;i<n;i++) {
      cur+=s[i];
      best=max(best,s[i]);
      while(cur<d[i]) {
         t+=k;
         cur+=best;
      }
      t+=d[i];
      cur-=d[i];
   }
   return t;
}

int main(void)
{  
   scanf("%d %d",&n,&k);
   for(int i=0;i<n;i++)
      scanf("%d",d+i);
   for(int i=0;i<n;i++)
      scanf("%d",s+i);
   printf("%d\n",solve());
   return 0;
}