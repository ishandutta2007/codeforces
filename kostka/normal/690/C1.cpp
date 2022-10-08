#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1007;

bool odw[MAXN];
vector <int> G[MAXN];

void dfs(int v)
{
  odw[v] = true;
  for(auto w : G[v])
    if(odw[w] == false)
      dfs(w);
}

bool check()
{
  int n, m;
  cin >> n >> m;
  if(m+1 != n)
    return false;
  while(m--)
  {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(1);
  for(int i=1; i<=n; i++)
    if(odw[i] == false)
      return false;
  return true;
}

int main()
{
  puts(check() ? "yes" : "no");
}