#include "bits/stdc++.h"

using namespace std;

const int MAXN = 2007;
static int tab[MAXN][MAXN];
const int INF = 1000*1000*1000+7;
vector <pair <int, int> > G[MAXN];
int pol[MAXN];
long long odl[MAXN];

int find(int x)
{
  //printf("%d\n", x);
  if(pol[x] == x)
    return x;
  else
    return pol[x] = find(pol[x]);
}

bool unia(int a, int b)
{
  int fa = find(a);
  int fb = find(b);
  //printf("%d %d %d %d\n", a, b, fa, fb);
  if(fa == fb)
    return false;
  pol[fa] = fb;
  return true;
}

bool firstcheck(int n)
{
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
    {
      if(tab[i][j] != tab[j][i])
        return false;
      if((i!=j) && (tab[i][j] == 0))
        return false;
    }
  for(int i=1; i<=n; i++)
    if(tab[i][i] != 0)
      return false;
  return true;
}

void dfs(int v)
{
  for(int i=0; i<G[v].size(); i++)
    if(odl[G[v][i].first]==0)
    {
      odl[G[v][i].first] = odl[v] + G[v][i].second;
      dfs(G[v][i].first);
    }
}

bool secondcheck(int n)
{
  vector <pair <int, pair<int,int> > > E;
  for(int i=1; i<=n; i++)
    pol[i] = i;
  for(int i=1; i<=n; i++)
    for(int j=i+1; j<=n; j++)
      E.push_back(make_pair(tab[i][j], make_pair(i,j)));
  sort(E.begin(), E.end());
  for(int i=0; i<(int)E.size(); i++)
  {
    int waga = E[i].first;
    int p = E[i].second.first, q = E[i].second.second;
    if(unia(p,q))
    {
      //printf("!%d\n", waga);
      G[p].push_back(make_pair(q,waga));
      G[q].push_back(make_pair(p,waga));
    }
  }
  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=n; j++)
      odl[j] = 0;
    odl[i] = 1;
    dfs(i);
    for(int j=1; j<=n; j++)
    {
      //printf("%d %d: %d %d\n", i, j, tab[i][j], odl[j]-1);
      if(tab[i][j] != odl[j]-1)
        return false;
    }
  }
  return true;
}

int main()
{
  int n;
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      scanf("%d", &tab[i][j]);
  if(firstcheck(n) && secondcheck(n))
    puts("YES");
  else
    puts("NO");
  return 0;
}