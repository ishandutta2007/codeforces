#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 100500

using namespace std;

const long long infll=10000000000000000LL;
typedef pair<long long,int> pli;

int n,qn,cdiff,csame;
int type[MAXN],val[MAXN];
long long best[MAXN];

inline long long gain(int pc,int cc,int v) {
   if(pc==cc) return v*(long long)csame;
   else return v*(long long)cdiff;
}

long long solve() {
   long long opt=0;
   for(int i=0;i<=n;i++)
      best[i]=-infll;
   pli o1(0,0),o2(-infll,1);
   for(int i=0;i<n;i++) {
      int v=val[i],t=type[i];
      long long cur=-infll;
      // diff
      cur=max(cur,o1.first+gain(o1.second,t,v));
      cur=max(cur,o2.first+gain(o2.second,t,v));
      // same
      cur=max(cur,best[t]+gain(t,t,v));
      //
      opt=max(opt,cur);
      best[t]=max(best[t],cur);
      if(t==o1.second) {
         o1.first=max(o1.first,cur);
      } else if(t==o2.second) {
         o2.first=max(o2.first,cur);
         if(o2>o1) swap(o1,o2);
      } else {
         if(cur>o1.first) {
            o2=o1;
            o1=make_pair(cur,t);
         } else if(cur>o2.first) {
            o2=make_pair(cur,t);
         }
      }
   }
   return opt;
}

int main(void)
{
   scanf("%d %d",&n,&qn);
   for(int i=0;i<n;i++)
      scanf("%d",val+i);
   for(int i=0;i<n;i++)
      scanf("%d",type+i);
   for(int i=0;i<qn;i++) {
      scanf("%d %d",&csame,&cdiff);
      cout << solve() << endl;
   }
   return 0;
}