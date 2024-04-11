#include "bits/stdc++.h"

using namespace std;

const int MAXN = 200007, LOG = 20;
bool czy[MAXN];
int pre[MAXN], post[MAXN], tim, poz[MAXN];
int przodek[LOG][MAXN];
vector <int> G[MAXN];

void dfs(int v, int poziom = 0)
{
  czy[v] = true;
  pre[v] = ++tim;
  poz[v] = poziom;
  for(auto w : G[v])
  {
    if(czy[w] == false)
    {
      przodek[0][w] = v;
      dfs(w, poziom+1);
    }
  }
  post[v] = tim;
}

void lcaprep(int n)
{
  dfs(1);
  przodek[0][1] = 1;
  for(int i=1; i<LOG; i++)
    for(int v=1; v<=n; v++)
      przodek[i][v] = przodek[i-1][przodek[i-1][v]];
}

bool subtree(int a, int b)
{
  return pre[a] <= pre[b] and post[b] <= post[a];
}

int lca(int a, int b)
{
  if(a == b)
    return a;
  if(poz[a] < poz[b])
    swap(a, b);
  for(int i=LOG-1; i>=0; i--)
    if(!subtree(przodek[i][a], b))
      a = przodek[i][a];
  return przodek[0][a];
}

int odl(int a, int b)
{
  //cerr << a << " " << b << " " << lca(a,b) << "\n";
  //cerr << "P" << poz[a] << " " << poz[b] << " " << poz[lca(a,b)] << "\n";
  //cerr << poz[a] + poz[b] - 2 * poz[lca(a,b)] << "\n";
  return poz[a] + poz[b] - 2 * poz[lca(a,b)];
}


int main()
{
  int n;
  cin >> n;
  int x;
  cin >> x;
  pair <int, int> farest = {2, x};
  cout << 1 << "\n";
  G[2].push_back(x);
  G[x].push_back(2);
  for(int i=3; i<=n; i++)
  {
    int oj;
    cin >> oj;
    G[oj].push_back(i);
    G[i].push_back(oj);
  }
  lcaprep(n);
  for(int i=3; i<=n; i++)
  {
    int e1, e2;
    tie(e1, e2) = farest;
    if(odl(e1,i) > odl(farest.first, farest.second))
      farest = {e1, i};
    if(odl(e2,i) > odl(farest.first, farest.second))
      farest = {e2, i};
    cout << odl(farest.first, farest.second) << "\n";
  }
}