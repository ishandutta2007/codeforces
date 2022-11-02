#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 1000050

using namespace std;

const int p1=333331,p2=3333331;
long long pp1[MAXN],pp2[MAXN];

typedef pair<long long,long long> pll;
typedef pair<int,pll> pill;

int n,m;
vector<int> adj[MAXN];
pill h1[MAXN],h2[MAXN];

inline long long solve() {
   long long sol=0;
   for(int i=1;i<=n;i++) {
      long long v1=0,v2=0;
      for(int j=0;j<adj[i].size();j++) {
         v1+=pp1[adj[i][j]];
         v2+=pp2[adj[i][j]];
      }
      h1[i]=make_pair(adj[i].size(),make_pair(v1,v2));
      h2[i]=make_pair(adj[i].size()+1,make_pair(v1+pp1[i],v2+pp2[i]));
   }
   sort(h1+1,h1+n+1);
   sort(h2+1,h2+n+1);
   int c=0;
   for(int i=1;i<=n;i++) {
      if(i==1||h1[i]!=h1[i-1]) {
         sol+=(long long)c*(c-1)/2;
         c=1;
      }
      else c++;
   }
   sol+=(long long)c*(c-1)/2;
   c=0;
   for(int i=1;i<=n;i++) {
      if(i==1||h2[i]!=h2[i-1]) {
         sol+=(long long)c*(c-1)/2;
         c=1;
      }
      else c++;
   }
   sol+=(long long)c*(c-1)/2;
   return sol;
}

int main(void)
{
   scanf("%d %d",&n,&m);
   pp1[0]=pp2[0]=1;
   for(int i=1;i<=n;i++) {
      pp1[i]=pp1[i-1]*p1;
      pp2[i]=pp2[i-1]*p2;
   }
   for(int i=0;i<m;i++) {
      int v,u;
      scanf("%d %d",&v,&u);
      adj[v].push_back(u);
      adj[u].push_back(v);
   }
   cout << solve() << endl;
   return 0;
}