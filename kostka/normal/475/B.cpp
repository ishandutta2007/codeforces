#include "bits/stdc++.h"

using namespace std;

vector <int> G[457];
bool czy[457];

void dfs(int v)
{
  //cerr << v << "\n";
  czy[v] = 1;
  for(int i=0; i<G[v].size(); i++)
    if(czy[G[v][i]]==0)
      dfs(G[v][i]);
}

int main()
{
  int n, m;
  cin >> n >> m;
  string x, y;
  cin >> x >> y;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
    {
      if(j!=m && x[i-1]=='>')
        G[i*m+j].push_back(i*m+j+1);
      if(j!=1 && x[i-1]=='<')
        G[i*m+j].push_back(i*m+j-1);
      if(i!=n && y[j-1]=='v')
        G[i*m+j].push_back((i+1)*m+j);        
      if(i!=1 && y[j-1]=='^')
        G[i*m+j].push_back((i-1)*m+j);        
    }
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
    {
      for(int k=1; k<=n; k++)
        for(int l=1; l<=m; l++)
          czy[k*m+l] = 0;
      //cerr << i*m+j << "\n\n";
      dfs(i*m+j);
      for(int k=1; k<=n; k++)
        for(int l=1; l<=m; l++)
          if(czy[k*m+l]==0)
          {
            //printf("%d %d %d %d\n", i, j, k, l);
            puts("NO");
            return 0;
          }
    }
  puts("YES");
  return 0;
}