#include <cstdio>
#include <algorithm>
#define MAXN 1000050
#define MAXM 260

using namespace std;

class Coor {
   public:
      int x,y;
      Coor() {}
      Coor(int xi,int yi):x(xi),y(yi) {}
      void input() {
         scanf("%d %d",&x,&y);
      }
};

int n,m;
Coor pt[MAXM];
int see[MAXN];

inline long long cross(Coor a,Coor b) {
   return (long long)a.x*b.y-(long long)a.y*b.x;
}
inline long long cross(Coor o,Coor a,Coor b) {
   return cross(Coor(a.x-o.x,a.y-o.y),Coor(b.x-o.x,b.y-o.y));
}

inline int solve() {
   for(int i=1;i<=n;i++)
      see[i]=1;
   for(int i=0;i<m;i++) {
      for(int j=i+1;j<m;j++) {
         Coor p=pt[i],q=pt[j];
         if(p.y==q.y) continue;
         if(p.y>q.y) swap(p,q);
         int cnt=0;
         for(int k=0;k<m;k++)
            if(cross(p,q,pt[k])==0) cnt++;
         // p.x+(p.x-q.x)*p.y/(q.y-p.y)
         long long c=(p.x-q.x)*(long long)p.y;
         long long d=(q.y-p.y);
         if(c%d) continue;
         long long x=p.x+c/d;
         if(x<1||x>n) continue;
         see[x]=max(see[x],cnt);
      }
   }
   int sol=0;
   for(int i=1;i<=n;i++)
      sol+=see[i];
   return sol;
}

int main(void)
{
   scanf("%d %d",&n,&m);
   for(int i=0;i<m;i++) 
      pt[i].input();
   printf("%d\n",solve());
   return 0;
}