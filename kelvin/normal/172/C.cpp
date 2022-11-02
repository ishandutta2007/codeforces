#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAXN 100050

using namespace std;

typedef pair<int,int> pii;

int n,cap;
vector<pii> bus;
int sol[MAXN];

inline int depart(int t) {
   //puts("!");
   sort(bus.begin(),bus.end());
   int d=0;
   int j;
   for(int i=0;i<(int)bus.size();i=j) {
      int x=bus[i].first;
      //for(j=i;j<(int)bus.size()&&bus[j].first==x;j++);
      for(j=i;j<(int)bus.size()&&bus[j].first==x;j++) {
         int v=bus[j].second;
         sol[v]=t+x+d;
      }
      int c=j-i;
      d+=1+c/2;
   }
   return d+2*bus.back().first;
}

int main(void)
{
   scanf("%d %d",&n,&cap);
   int t=0;
   for(int i=0;i<n;i++) {
      int x,t2;
      scanf("%d %d",&t2,&x);
      if(t2>t) t=t2;
      bus.push_back(make_pair(x,i));
      if((i+1)%cap==0||i==n-1) {
         t+=depart(t);
         bus.clear();
      }
   }
   for(int i=0;i<n;i++)
      printf("%d%c",sol[i],i<n-1?' ':'\n');
   return 0;
}