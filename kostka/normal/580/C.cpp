//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100007;

bool cat[MAXN], odw[MAXN];
vector <int> G[MAXN];
int m, ile;

void dfs(int a, int b=0)
{
  odw[a] = true;
  if(cat[a] == true)
    b++;
  else
    b = 0;
  if(b > m)
    return;
  for(auto ele : G[a])
    if(odw[ele] == false)
      dfs(ele, b);
  if(a!=1 and (int)G[a].size() == 1)
    ile++;
}

int main()
{
  int n;
  cin >> n >> m;
  for(int i=1; i<=n; i++)
    cin >> cat[i];
  for(int i=1; i<n; i++)
  {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(1);
  cout << ile << "\n";
  return 0;
}