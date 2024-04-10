#include <stdio.h>
#include <math.h>
#define MAXN 100500

int _dummy;

int n,qn,gn,gsz,inf;
int jump[MAXN],skipdes[MAXN],skipcnt[MAXN];

inline int min(int a,int b) { return a<b?a:b; }

inline void walk(int x,int &des,int &cnt) {
   int gi=x/gsz;
   int glast=min((gi+1)*gsz-1,n-1);
   cnt=0;
   while(x<=glast) {
      x=x+jump[x];
      cnt++;
   }
   des=x;
}

inline void pre() {
   gsz=sqrt(n)+5;
   gn=(n+gsz-1)/gsz;
   inf=gn*gsz;
   for(int i=0;i<n;i++)
      walk(i,skipdes[i],skipcnt[i]);
}

inline void go(int x) {
   int cnt=0;
   while(1) {
      cnt+=skipcnt[x];
      if(skipdes[x]>=n) break;
      x=skipdes[x];
   }
   while(x+jump[x]<n)
      x=x+jump[x];
   printf("%d %d\n",x+1,cnt);
}

inline void set(int x,int a) {
   int gi=x/gsz;
   int gfirst=gi*gsz;
   int glast=min(gfirst+gsz-1,n-1);
   jump[x]=a;
   for(int i=x;i>=gfirst;i--) {
      int ni=i+jump[i];
      if(ni<=glast) {
         skipdes[i]=skipdes[ni];
         skipcnt[i]=skipcnt[ni]+1;
      } else {
         skipdes[i]=ni;
         skipcnt[i]=1;
      }
   }
}

inline void solve() {
   int op,x,a;
   pre();
   for(int i=0;i<qn;i++) {
      scanf("%d",&op);
      if(op) {
         scanf("%d",&x);
         go(--x);
      } else {
         scanf("%d %d",&x,&a);
         set(--x,a);
      }
   }
}

int main(void)
{
   while(scanf("%d %d",&n,&qn)==2) {
      for(int i=0;i<n;i++)
         scanf("%d",jump+i);
      solve();
   }
   return 0;
}