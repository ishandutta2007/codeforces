//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 10007;
vector <pair <int, int> > G[MAXN];
const int INF = 1e9+7;
vector <pair <int, int> > X;

int dijkstra(int st, int ko, int k)
{
  vector <int> dist(k+1, INF);
  vector <bool> ok(k+1);
  dist[st] = 0;
  priority_queue <pair <int, int> > Q;
  Q.emplace(0, st);
  while(!Q.empty())
  {
    int v = Q.top().second;
    Q.pop();
    if(ok[v])
      continue;
    ok[v] = true;
    int a1, a2, b1, b2;
    tie(a1, b1) = X[v];
    for(int w=0; w<(int)X.size(); w++)
    {
      if(v == w)
        continue;
      tie(a2, b2) = X[w];
      bool unlit = (v == k or w == k);
      int cost = INF;
      if(abs(a2-a1) + abs(b2-b1) == 1)
        cost = unlit ? 1 : 0;
      else if(abs(a2-a1) <= 1 or abs(b2-b1) <= 1)
        cost = 1;
      else if(not(unlit) and (abs(a2-a1) <= 2 or abs(b2-b1) <= 2))
        cost = 1;
      if(cost != INF)
      {
        if(dist[w] > dist[v] + cost)
        {
          dist[w] = dist[v] + cost;
          Q.emplace(-dist[w], w);
        }
      }
    }
  }
  //cerr << dist[ko] << "\n";
  return dist[ko];
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  int st = -1, ko = -1;
  for(int i=0; i<k; i++)
  {
    int a, b;
    cin >> a >> b;
    X.emplace_back(a,b);
    if(a == 1 and b == 1)
      st = i;
    if(a == n and b == m)
      ko = i;
  }
  if(ko == -1)
  {
    ko = k;
    X.emplace_back(n, m);
  }
  int res = dijkstra(st, ko, max(ko, k));
  if(res >= INF)
    res = -1;
  cout << res << "\n";
}