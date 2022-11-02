#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 1050000

using namespace std;

int n,m;
vector<int> adj[MAXN];

int main(void)
{
   scanf("%d %d",&n,&m);
   for(int i=0;i<m;i++) {
      int v,u;
      scanf("%d %d",&v,&u);
      v--; u--;
      adj[v].push_back(u);
      adj[u].push_back(v);
   }
   long long sum=0;
   for(int i=0;i<n;i++) {
      int c[2]={0,0};
      for(int t=0;t<adj[i].size();t++) {
         int j=adj[i][t];
         c[1]++;
      }
      c[0]=(n-1)-c[1];
      sum+=(long long)c[0]*(c[0]-1)+(long long)c[1]*(c[1]-1)-(long long)c[0]*c[1];
   }
   sum/=6;
   cout << sum << endl;
   return 0;
}