//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 200007;
int p[MAXN];
int odw[MAXN];
vector <int> G[MAXN];

int root = -1;
int res = 0;

void dfs(int v, int t)
{
  odw[v] = t;
  while(odw[p[v]] == 0)
  {
    odw[p[v]] = t;
    v = p[v];
  }
  //cerr << v << " " << p[v] << " " << root << "\n";
  if(odw[p[v]] == t)
  {
    if(root == -1)
      root = v;
    if(p[v] != root)
    {
      p[v] = root;
      res++;
    }
  }
}

int main()
{
  int n;
  cin >> n;
  for(int i=1; i<=n; i++)
  {
    cin >> p[i];
    if(i == p[i])
      root = i;
    G[i].push_back(p[i]);

  }
  int tim = 0;
  for(int i=1; i<=n; i++)
  {
    if(odw[i] == false)
      dfs(i, ++tim);
  }
  cout << res << "\n";
  for(int i=1; i<=n; i++)
    cout << p[i] << " ";
  cout << "\n";
  return 0;
}