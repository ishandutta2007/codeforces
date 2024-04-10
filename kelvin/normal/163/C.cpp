#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#define MAXN 100050

using namespace std;

typedef pair<int,int> PII;

const int epow=14;
long double eps;

inline long double abs(long double x) { return x>=0.0? x:-x; }
inline bool iszero(long double x) { return abs(x)<eps; }
inline bool equal(long double a,long double b) { return iszero(a-b); }

class Event {
   public:
      long double t;
      int a;
      Event(long double _t,int _a):t(_t),a(_a) {}
      const bool operator<(const Event &b) const {
         if(!equal(t,b.t)) return t<b.t;
         return a>b.a;
      }
};

int n,l,v1,v2;
int pos[MAXN];
vector<Event> event;
long double sol[MAXN*2];

inline void solve() {
   int c=0;
   long double d=(long double)v2/(v1+v2)*l;
   for(int i=0;i<n;i++) {
      long double t1=pos[i]-d;
      long double t2=pos[i];
      if(t1<0.0-eps) t1+=2*l;
      event.push_back(Event(t1,1));
      event.push_back(Event(t2,-1));
      if(t1>t2) c++;
   }
   sort(event.begin(),event.end());
   long double pt=0.0;
   for(int i=0;i<=n;i++)
      sol[i]=0.0;
   for(int i=0;i<event.size();i++) {
      Event e=event[i];
      long double t=e.t;
      int a=e.a;
      //printf("<%d>\n",c);
      if(!iszero(t-pt)) sol[c]+=t-pt;
      pt=t;
      c+=a;
   }
   sol[c]+=2*l-pt;
   for(int i=0;i<=n;i++) {
      sol[i]/=2*l;
      cout << setprecision(15) << sol[i] << endl;
   }
}

int main(void)
{
   eps=(long double)1.0;
   for(int i=0;i<epow;i++)
      eps/=10;
   scanf("%d %d %d %d",&n,&l,&v1,&v2);
   for(int i=0;i<n;i++)
      scanf("%d",pos+i);
   solve();
   return 0;
}