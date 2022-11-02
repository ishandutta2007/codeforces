#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAXN 300050

using namespace std;

typedef long long ll;

class Query {
   public:
      int s,d,r,id;
      void input() { scanf("%d %d",&s,&d); s--; r=s%d; }
      const bool operator<(const Query &b) const {
         if(d!=b.d) return d<b.d;
         if(r!=b.r) return r<b.r;
         return 0;
      }
};

int sn,qn;
long long s[MAXN];
Query q[MAXN];
long long sol[MAXN];
long long arr[MAXN];

inline void solve() {
   int qi,qj,qe,i,d,r,st,ed;
   ll mm;
   sort(q,q+qn);
   for(qi=0;qi<qn;qi=qj) {
      d=q[qi].d;
      r=q[qi].r;
      for(qe=qi;qe<qn&&q[qe].d==d&&q[qe].r==r;qe++);
      arr[r]=s[r];
      for(i=r+d;i<sn;i+=d)
         arr[i]=arr[i-d]+s[i];
      ed=i-d;
      for(qj=qi;qj<qe;qj++) {
         st=q[qj].s;
         if(st==r) mm=0;
         else mm=arr[st-d];
         sol[q[qj].id]=arr[ed]-mm;
      }
   }
   for(i=0;i<qn;i++) {
      cout << sol[i];
      if(i<qn-1) cout << ' ';
      else cout << endl;
   }
}

int main(void)
{
   int i;
   while(cin>>sn) {
      for(i=0;i<sn;i++)
         cin>>s[i];
      cin>>qn;
      for(i=0;i<qn;i++) {
         q[i].input();
         q[i].id=i;
      }
      solve();
   }
   return 0;
}