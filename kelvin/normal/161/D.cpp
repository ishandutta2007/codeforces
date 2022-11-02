#include <stdio.h>
#include <iostream>
#include <vector>
#define MAXN 50500
#define MAXK 505

using namespace std;

int n,k;
vector<int> adj[MAXN];
int dp[MAXN][MAXK]={0};
long long sol=0;

void dfs(int v,int p) {
   dp[v][0]=1;
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      if(u==p) continue;
      dfs(u,v);
      for(int j=0;j<k;j++)
         sol+=(long long)dp[u][j]*dp[v][k-j-1];
      for(int j=0;j<k;j++)
         dp[v][j+1]+=dp[u][j];
   }
}

inline long long solve() {
   dfs(1,0);
   return sol;
}

int main(void)
{
   scanf("%d %d",&n,&k);
   for(int i=0;i<n-1;i++) {
      int v,u;
      scanf("%d %d",&v,&u);
      adj[v].push_back(u);
      adj[u].push_back(v);
   }
   cout << solve() << endl;
   return 0;
}