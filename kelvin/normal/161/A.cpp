#include <stdio.h>
#include <algorithm>
#include <vector>
#define MAXN 100050

using namespace std;

typedef pair<int,int> pii;

int an,bn,ld,rd;
int a[MAXN],b[MAXN];
vector<pii> sol;

inline void solve() {
   int j=0;
   for(int i=0;i<an;i++) {
      while(j<bn&&b[j]<a[i]-ld) j++;
      if(j<bn&&b[j]<=a[i]+rd) sol.push_back(make_pair(i,j++));
   }
   printf("%d\n",sol.size());
   for(int i=0;i<sol.size();i++)
      printf("%d %d\n",sol[i].first+1,sol[i].second+1);
}

int main(void)
{
   scanf("%d %d %d %d",&an,&bn,&ld,&rd);
   for(int i=0;i<an;i++)
      scanf("%d",a+i);
   for(int i=0;i<bn;i++)
      scanf("%d",b+i);
   solve();
   return 0;
}