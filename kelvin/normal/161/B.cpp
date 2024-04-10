#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 1050

using namespace std;

typedef pair<int,int> pii;

int totn,nkart;
int an,bn;
int orig[MAXN];
pii a[MAXN],b[MAXN];

vector<int> sol[MAXN];
int kt[MAXN];

inline bool cmp(int a,int b) {
   return orig[a]<orig[b];
}

inline void output() {
   long long totcost=0,totdis=0;
   for(int i=0;i<nkart;i++) {
      sort(sol[i].begin(),sol[i].end(),cmp);
      if(i<an) totdis+=orig[sol[i][0]];
      for(int j=0;j<sol[i].size();j++)
         totcost+=orig[sol[i][j]];
   }
   totcost=totcost*2-totdis;
   cout<<totcost/2<<'.'<<((totcost&1)?5:0)<<endl;
   for(int i=0;i<nkart;i++) {
      printf("%d",sol[i].size());
      for(int j=0;j<sol[i].size();j++)
         printf(" %d",sol[i][j]+1);
      puts("");
   }
}

inline void solve() {
   std::sort(a,a+an);
   std::sort(b,b+bn);
   for(int i=0;i<an;i++)
      sol[min(i,nkart-1)].push_back(a[an-i-1].second);
   int rem=max(nkart-an,0);
   for(int i=0;i<rem;i++)
      sol[nkart-i-1].push_back(b[i].second);
   for(int i=rem;i<bn;i++)
      sol[nkart-1].push_back(b[i].second);
   output();
}

int main(void)
{
   scanf("%d %d",&totn,&nkart);
   an=bn=0;
   for(int i=0;i<totn;i++) {
      int c,t;
      scanf("%d %d",&c,&t);
      orig[i]=c;
      if(t==1) a[an++]=make_pair(c,i);
      else b[bn++]=make_pair(c,i);
   }
   solve();
   return 0;
}