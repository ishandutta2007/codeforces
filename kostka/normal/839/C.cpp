//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100007;
vector <int> G[MAXN];
bool vis[MAXN];

double dfs(int v)
{
  vis[v] = true;
  double res = 0.0;
  int ile = 0;
  for(auto w : G[v])
  {
    if(!vis[w])
    {
      res += 1+dfs(w);
      ile++;
    }
  }
  return ile ? res/ile : 0.0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i=1; i<n; i++)
  {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);

  }
  cout << fixed << setprecision(10) << dfs(1) << "\n";
  return 0;
}