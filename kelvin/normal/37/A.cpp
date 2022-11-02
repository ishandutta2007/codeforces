#include <stdio.h>
#include <map>

using namespace std;

inline int max(int a,int b) { return a>b?a:b; }

int main(void)
{
   int n,m=0;
   map<int,int> cnt;
   scanf("%d",&n);
   for(int t=0;t<n;t++) {
      int x;
      scanf("%d",&x);
      cnt[x]++;
      m=max(cnt[x],m);
   }
   printf("%d %d\n",m,cnt.size());
   return 0;
}