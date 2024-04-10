#include <stdio.h>
#include <queue>
#include <algorithm>
#define MAXN 100050

using namespace std;

typedef pair<int,int> pii;
int n,sz[MAXN];

int sn,sol[MAXN][3];

inline void solve() {
   priority_queue<pii> pq;
   sort(sz,sz+n);
   int cnt;
   for(int i=0;i<n;i++) {
      if(i==0||sz[i]!=sz[i-1]) {
         if(i) pq.push(make_pair(cnt,sz[i-1]));
         cnt=1;
      } else {
         cnt++;
      }
   }
   pq.push(make_pair(cnt,sz[n-1]));
   //printf("%d\n",pq.size());
   sn=0;
   while(pq.size()>=3) {
      pii a=pq.top(); pq.pop();
      pii b=pq.top(); pq.pop();
      pii c=pq.top(); pq.pop();
      sol[sn][0]=a.second;
      sol[sn][1]=b.second;
      sol[sn][2]=c.second;
      if(a.first>1) pq.push(make_pair(a.first-1,a.second));
      if(b.first>1) pq.push(make_pair(b.first-1,b.second));
      if(c.first>1) pq.push(make_pair(c.first-1,c.second));
      sn++;
   }
   printf("%d\n",sn);
   for(int i=0;i<sn;i++) {
      std::sort(sol[i],sol[i]+3);
      printf("%d %d %d\n",sol[i][2],sol[i][1],sol[i][0]);
   }
}

int main(void)
{
   scanf("%d",&n);
   for(int i=0;i<n;i++)
      scanf("%d",sz+i);
   solve();
   return 0;
}