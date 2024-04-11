//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 200007;
vector <int> G[MAXN];
bool odw[MAXN];
vector <int> PIA;

void dfs(int v)
{
  odw[v] = true;
  PIA.push_back(v);
  for(auto w : G[v])
    if(odw[w] == false)
    {
      dfs(w);
      PIA.push_back(v);
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  for(int i=0; i<m; i++)
  {
    int x, y;
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  dfs(1);
  if(n != 1)
    PIA.pop_back();
  if(n == 1 and k == 1)
  {
    cout << "1 1\n";
    return 0;
  }
  int dz = (2*n + k - 1) / k;
  int cur = 0;
  for(int i=0; i<k; i++)
  {
    cout << dz << " ";
    for(int j=0; j<dz; j++)
    {
      cout << PIA[cur++] << " ";
      if(cur == (int)PIA.size())
        cur = 0;
    }
    cout << "\n";
  }
  return 0;
}