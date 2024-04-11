#include "bits/stdc++.h"

using namespace std;

vector <int> G[100007];
vector <pair <int, int> > X;
bool odw[100007];
int tab[100007], rep[100007], ile[100007];
long long next = 0;

int find(int x)
{
  if(rep[x]==x)
    return x;
  return rep[x] = find(rep[x]);
}

void unia(int a, int b)
{
  int fa = find(a), fb = find(b);
  if(fa != fb)
  {
    rep[fa] = fb;
    next -= 1LL*ile[fa]*(ile[fa]-1);
    next -= 1LL*ile[fb]*(ile[fb]-1);
    ile[fb] += ile[fa];
    ile[fa] = 0;
    next += 1LL*ile[fb]*(ile[fb]-1);
  }
}

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; i++)
  {
    scanf("%d", &tab[i]);
    X.push_back(make_pair(-tab[i],i));
    rep[i] = i;
    ile[i] = 1;
  }
  while(m--)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  long long duzo = 1LL*n*(n-1);
  sort(X.begin(), X.end());
  long long prev = 0;
  long long wyn = 0;
  for(int i=0; i<n; )
  {
    int w = -X[i].first;
    while(i<n && w==-X[i].first)
    {
      int v = X[i].second;
      odw[v] = 1;
      for(int j=0; j<G[v].size(); j++)
        if(odw[G[v][j]]==1)
          unia(v, G[v][j]);
      i++;
      //printf("%lld\n", next);
    }
    long long ile = next-prev;
    prev = next;
    wyn += w*ile;
  }
  double res = (double)(1.0*wyn/duzo);
  printf("%.10lf\n", res);
}