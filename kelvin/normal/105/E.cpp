#include <stdio.h>
#include <string.h>
#include <set>
#define MAXL 42

using namespace std;

class State {
   public:
      int x[3],h[3];
      bool moved[3];
      bool lifted[3];
      State(int x0=0,int x1=0,int x2=0) {
         x[0]=x0;
         x[1]=x1;
         x[2]=x2;
         memset(h,0,sizeof(h));
         memset(moved,0,sizeof(moved));
         memset(lifted,0,sizeof(lifted));
      }
      void extract(int *_x,int *_h,bool *_moved,bool *_lifted) {
         for(int i=0;i<3;i++) {
            _x[i]=x[i];
            _h[i]=h[i];
            _moved[i]=moved[i];
            _lifted[i]=lifted[i];
         }
      }
      const bool operator<(const State &b) const {
         for(int i=0;i<3;i++) {
            if(x[i]!=b.x[i]) return x[i]<b.x[i];
            if(h[i]!=b.h[i]) return h[i]<b.h[i];
            if(moved[i]!=b.moved[i]) return moved[i]<b.moved[i];
            if(lifted[i]!=b.lifted[i]) return lifted[i]<b.lifted[i];
         }
      }
};

int beg[3],rng[3],str[3];
set<State> visited;
int far;

inline int max(int a,int b) { return a>b?a:b; }
inline int max(int a,int b,int c) { return max(a,max(b,c)); }
inline int max(int a,int b,int c,int d) { return max(max(a,b),max(c,d)); }
inline int dist(int a,int b) { return a>b?a-b:b-a; }

void dfs(State s) {
   int x[3],h[3];
   bool moved[3];
   bool lifted[3];
   State ns;
   visited.insert(s);
   s.extract(x,h,moved,lifted);
   far=max(far,x[0],x[1],x[2]);
   for(int i=0;i<3;i++) {
      int i1=(i+1>=3?i-2:i+1),i2=(i+2>=3?i-1:i+2);
      /* move */
      if(!moved[i]&&x[i]!=x[i1]&&x[i]!=x[i2]) {
         for(int j=max(1,x[i]-rng[i]);j<=x[i]+rng[i];j++) {
            if(j==x[i1]||j==x[i2]) continue;
            ns=s;
            ns.x[i]=j;
            ns.moved[i]=1;
            if(visited.find(ns)==visited.end()) dfs(ns);
         }
      }
      /* lift */
      if(!lifted[i]&&x[i]!=x[i1]&&x[i]!=x[i2]) {
         for(int j=0;j<3;j++) {
            if(j==i) continue;
            if(dist(x[i],x[j])!=1) continue;
            int o=3-i-j;
            ns=s;
            if(ns.x[o]==ns.x[j]) {
               ns.h[o]++;
               ns.x[o]=x[i];
            }
            ns.h[j]++;
            ns.x[j]=x[i];
            ns.lifted[i]=1;
            if(visited.find(ns)==visited.end()) dfs(ns);
         }
      }
      /* throw */
      if(h[i]==0&&(x[i]==x[i1]||x[i]==x[i2])) {
         int m=(h[i1]==1?i1:i2);
         int o=3-i-m;
         for(int j=max(1,x[i]-str[i]);j<=x[i]+str[i];j++) {
            if(j==x[i]||j==x[i1]||j==x[i2]) continue;
            ns=s;
            if(ns.x[o]==ns.x[i]) {
               ns.h[o]--;
               ns.x[o]=j;
            }
            ns.h[m]--;
            ns.x[m]=j;
            if(visited.find(ns)==visited.end()) dfs(ns);
         }
      }
   }
}

inline int solve() {
   far=0;
   dfs(State(beg[0],beg[1],beg[2]));
   return far;
}

int main(void)
{
   for(int i=0;i<3;i++)
      scanf("%d %d %d",beg+i,rng+i,str+i);
   printf("%d\n",solve());
   return 0;
}