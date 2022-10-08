#include "bits/stdc++.h"

using namespace std;

queue <int> Q;

const int MAXN = 100007;
vector <int> G[MAXN];
int odw[MAXN], odl[MAXN];

int dfs(int v, int pre = -1)
{
  //cerr << v << "\n";
  odw[v] = 1;
  for(int i=0; i<(int)G[v].size(); i++)
  {
    if(G[v][i] == pre)
      continue;
    if(odw[G[v][i]] == 1)
    {
      Q.push(v);
      odl[v] = 0;
      //cerr << G[v][i] << "\n";
      return G[v][i];
    }
    if(odw[G[v][i]] == 0)
    {
      int e = dfs(G[v][i], v);
      if(e != -1)
      {
        Q.push(v);
        odl[v] = 0;
        if(e == v)
          e = -1;
        return e;
      }
    }
  }
  odw[v] = 2;
  return -1;
}

int main()
{
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
  {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for(int i=1; i<=n; i++)
    odl[i] = -1;
  dfs(1);
  while(!Q.empty())
  {
    int w = Q.front();
    Q.pop();
    for(int i=0; i<(int)G[w].size(); i++)
    {
      if(odl[G[w][i]] == -1)
      {
        odl[G[w][i]] = odl[w]+1;
        Q.push(G[w][i]);
      }
    }
  }
  for(int i=1; i<=n; i++)
    cout << odl[i] << " ";
  return 0;
}