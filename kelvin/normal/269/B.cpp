#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 5050

using namespace std;
const int inf=100000000;

int n,m;
int s[MAXN];
int lis[MAXN];

int solve() {
   int ll=0;
   for(int i=0;i<n;i++) {
      int l=-1,r=ll,m;
      while(l<r-1) {
         int m=(l+r)>>1;
         if(lis[m]<=s[i]) l=m;
         else r=m;
      }
      if(r==ll) ll++;
      lis[r]=s[i];
   }
   return n-ll;
}

int main(void)
{
   scanf("%d %d",&n,&m);
   for(int i=0;i<n;i++)
      scanf("%d %*lf",s+i);
   printf("%d\n",solve());
   return 0;
}