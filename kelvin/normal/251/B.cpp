#include <cstdio>
#include <iostream>
#define MAXN 105

using namespace std;

const int inf=10000;

int n,k;
int s[MAXN];
int g[MAXN];
int q[MAXN],iq[MAXN];

inline void apply(int *s,int *q,int *t) {
   for(int i=0;i<n;i++)
      t[i]=s[q[i]];
}

inline bool equal(int *s,int *t) {
   for(int i=0;i<n;i++)
      if(s[i]!=t[i]) return 0;
   return 1;
}

inline void copy(int *s,int *t) {
   for(int i=0;i<n;i++)
      t[i]=s[i];
}
inline void apply_in_place(int *s,int *q) {
   int t[MAXN];
   apply(s,q,t);
   copy(t,s);
}

bool solve() {
   for(int i=0;i<n;i++)
      iq[q[i]]=i;
   for(int i=0;i<n;i++)
      s[i]=i;
   if(equal(s,g)) return 0;
   int t[MAXN];
   int m1=inf,m2=inf;
   copy(s,t);
   for(int i=0;i<k;i++) {
      apply_in_place(t,q);
      //for(int j=0;j<n;j++)
         //printf()
      if(equal(t,g)) {
         m1=i+1;
         break;
      }
   }
   copy(s,t);
   for(int i=0;i<k;i++) {
      apply_in_place(t,iq);
      if(equal(t,g)) {
         m2=i+1;
         break;
      }
   }
   if(k==1) return m1==1||m2==1;
   if(m1<=1&&m2<=1) return 0;
   return (m1<=k&&(m1&1)==(k&1))||(m2<=k&&(m2&1)==(k&1));
}

int main(void)
{
   scanf("%d %d",&n,&k);
   for(int i=0;i<n;i++) {
      scanf("%d",q+i);
      q[i]--;
   }
   for(int i=0;i<n;i++) {
      scanf("%d",g+i);
      g[i]--;
   }
   puts(solve()?"YES":"NO");
   return 0;
}