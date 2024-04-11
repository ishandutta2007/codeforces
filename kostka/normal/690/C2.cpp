#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100007;

bool odw[MAXN];
int odl[MAXN];
vector <int> G[MAXN];

void dfs(int v)
{
  odw[v] = true;
  for(auto w : G[v])
    if(odw[w] == false)
    {
      odl[w] = odl[v] + 1;
      dfs(w);
    }
}

int main()
{
  int n, m;
  cin >> n >> m;
  while(m--)
  {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(1);
  int maks = 1;
  for(int i=1; i<=n; i++)
    if(odl[maks] < odl[i])
      maks = i;
  memset(odw, 0, sizeof(odw));
  memset(odl, 0, sizeof(odl));
  dfs(maks);
  int res = 0;
  for(int i=1; i<=n; i++)
    res = max(res, odl[i]);
  cout << res << "\n";
}