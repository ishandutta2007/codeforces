//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100007;
vector <pair<int, bool>> G[MAXN];
int change[MAXN];
int odl[MAXN], prz[MAXN];

void bfs(int v)
{
  queue <int> Q;
  Q.push(v);
  odl[v] = 1;
  change[1] = 0;
  while(!Q.empty())
  {
    int w = Q.front();
    Q.pop();
    for(auto ele : G[w])
    {
      int x = ele.first;
      bool blo = ele.second;
      if(odl[w] == odl[x]+1)
        if(change[w] > change[x]+(1-blo))
        {
          change[w] = min(change[w], change[x]+(1-blo));
          prz[w] = x;
        }
    }
    for(auto ele : G[w])
    {
      int x = ele.first;
      if(odl[x]==0)
      {
        odl[x] = odl[w]+1;
        Q.push(x);
      }
    }
  }
}

vector <pair <pair <int, int>, bool> > E;
set <pair <int, int> > S;

void back(int v)
{
  if(v==1)
    return;
  int e = prz[v];
  S.insert({min(e,v),max(e,v)});
  back(e);
}

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i=1; i<=n; i++)
    change[i] = 1<<30;
  int e = 0, f = 0;
  for(int i=0; i<m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    if(c==0)
      f++;
    else
      e++;
    G[a].push_back({b,c});
    G[b].push_back({a,c});
    E.push_back({{min(a,b),max(a,b)},c});
  }
  bfs(1);
  cout << e-(odl[n]-1-change[n])+change[n] << "\n";
  back(n);
  for(auto ele : E)
  {
    int a = ele.first.first;
    int b = ele.first.second;
    bool czy = ele.second;
    if(S.find({a,b})==S.end())
    {
      if(czy == 1)
        cout << a << " " << b << " 0\n";
    }
    else
    {
      if(czy == 0)
        cout << a << " " << b << " 1\n";
    }
  }
  return 0;
}