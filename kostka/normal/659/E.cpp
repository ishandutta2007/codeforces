//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100007;
vector <int> G[MAXN];
int odw[MAXN];


bool dfs(int v, int prz = -1)
{
  odw[v] = 1;
  bool res = false;
  for(auto w : G[v])
  {
    if(w == prz)
      continue;
    if(odw[w] == 1)
      res = true;
    if(odw[w] == 0)
      res |= dfs(w, v);
  }
  odw[v] = 2;
  return res;
}

int main()
{
  int n, m;
  cin >> n >> m;
  while(m--)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  int ile = 0;
  for(int i=0; i<n; i++)
    if(odw[i] == false)
      if(dfs(i) == false)
        ile++;
  cout << ile << "\n";
  return 0;
}