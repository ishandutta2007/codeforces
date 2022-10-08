//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 200007;
const int MOD = 1000*1000*1000+7;
vector <int> G[MAXN];
int prop[MAXN], cykl[MAXN];
int cyc;
bool iscykl[MAXN], odw[MAXN];

void dfs(int v, int ile)
{
  //cerr << ile << " " << v << "\n";
  cykl[v] = ile;
  if(prop[v] == 0)
    return;
  if(v == prop[v])
   {
    iscykl[ile] = true;
    return;
  }
  if(cykl[prop[v]] == ile)
  {
    //cerr << v << "\n";
    cyc++;
    iscykl[ile] = true;
    return;
  }
  if(!cykl[prop[v]])
    dfs(prop[v], ile);
  iscykl[ile] = iscykl[cykl[prop[v]]];
}

int dfs(int v)
{
  odw[v] = true;
  int res = 1;
  for(auto w : G[v])
    if(!odw[w])
      res += dfs(w);
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i=1; i<=n; i++)
  {
    int a, b;
    cin >> a >> b;
    prop[a] = b;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  int ile = 0;
  for(int i=1; i<=2*n; i++)
    if(!cykl[i])
      dfs(i, ++ile);
  //cerr << cyc << "\n";
  long long res = 1;
  for(int i=0; i<cyc; i++)
  {
    res *= 2;
    res %= MOD;
  }
  for(int i=1; i<=2*n; i++)
  {
    //cerr << i << " " << iscykl[cykl[i]] << "\n";
    if(!odw[i] and !iscykl[cykl[i]])
    {
      res *= dfs(i);
      res %= MOD;
    }
  }
  cout << res << "\n";
  return 0;
}