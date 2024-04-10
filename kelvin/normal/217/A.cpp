#include <cstdio>
#include <algorithm>
#define MAXN 105

using namespace std;

typedef pair<int,int> pii;

class DisjointSet {
   public:
      int n;
      int r[MAXN];
      void init(int _n) {
         n=_n;
         for(int i=0;i<n;i++)
            r[i]=i;
      }
      DisjointSet(int _n) {
         init(_n);
      }
      int rep(int v) {
         if(r[v]!=v) r[v]=rep(r[v]);
         return r[v];
      }
      bool merge(int v,int u) {
         v=rep(v);
         u=rep(u);
         if(v==u) return 0;
         r[v]=u;
         return 1;
      }
};

class Point {
   public:
      int x,y,id;
      void input() {
         scanf("%d %d",&x,&y);
      }
};

int n;
Point pt[MAXN];

bool cmpx(Point a,Point b) {
    return a.x<b.x;
}
bool cmpy(Point a,Point b) {
    return a.y<b.y;
}

int solve() {
   int g=n;
   DisjointSet djs(n);
   sort(pt,pt+n,cmpx);
   for(int i=0;i<n-1;i++)
      if(pt[i].x==pt[i+1].x) g-=djs.merge(pt[i].id,pt[i+1].id);
   sort(pt,pt+n,cmpy);
   for(int i=0;i<n-1;i++)
      if(pt[i].y==pt[i+1].y) g-=djs.merge(pt[i].id,pt[i+1].id);
   return g-1;
}

int main(void)
{
   scanf("%d",&n);
   for(int i=0;i<n;i++) {
      pt[i].input();
      pt[i].id=i;
      //scanf("%d %d",&(pt[i].first),&(pt[i].second));
   }
   printf("%d\n",solve());
   return 0;
}