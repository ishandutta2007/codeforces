#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#define MAXN 200050

using namespace std;

class Segment {
   public:
      int l,r,c;
      void input() {
         scanf("%d %d %d",&l,&r,&c);
         l--; r--;
      }
      const bool operator<(const Segment &b) const {
         return r>b.r;
      }
};

int racen,roadn;
int res[MAXN];
Segment seg[MAXN];
long long sumall;
vector<Segment> arr[MAXN];

inline int min(int a,int b) { return a<b?a:b; }

inline long long solve() {
   long long f=0,push;
   priority_queue<Segment> pq;
   for(int i=0;i<roadn;i++) {
      for(int j=0;j<arr[i].size();j++)
         pq.push(arr[i][j]);
      while(!pq.empty()&&res[i]) {
         Segment s=pq.top();
         pq.pop();
         if(s.r<i) continue;
         push=min(res[i],s.c);
         res[i]-=push;
         s.c-=push;
         f+=push;
         if(s.c) pq.push(s);
      }
   }
   return sumall-f;
}

int main(void)
{
   scanf("%d %d",&roadn,&racen);
   for(int i=0;i<roadn;i++) {
      scanf("%d",res+i);
      arr[i].clear();
   }
   sumall=0;
   for(int i=0;i<racen;i++) {
      seg[i].input();
      sumall+=seg[i].c;
      arr[seg[i].l].push_back(seg[i]);
   }
   cout << solve() << endl;
   return 0;
}