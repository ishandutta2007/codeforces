#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1007;
bool odw[MAXN];
int d[MAXN], low[MAXN], ojc[MAXN], spo[MAXN];
int tim = 0;
unordered_set <int> G[MAXN];
vector <pair <int, int> > E = {{0,0}};

const int INF = 1e9 + 7;

const int MAXM = 30007;
int waga[MAXM];

unordered_set <int> M;

int drugi(int kr, int a)
{
  if(E[kr].first == a)
    return E[kr].second;
  return E[kr].first;
}

bool dfs(int v, int s = -1)
{
  odw[v] = 1;
  bool czy = false;
  for(auto ele : G[v])
  {
    int w = drugi(ele, v);
    if(odw[w] == false)
    {
       d[w] = d[v]+1;
       ojc[w] = ele;
       czy |= dfs(w, s);
    }
  }
  low[v] = d[v];
  for(auto ele : G[v])
  {
    int w = drugi(ele, v);
    //jest moim synem
    if(ojc[w] == ele)
    {
      low[v] = min(low[v], low[w]);
      continue;
    }

    //jest moim ojcem
    if(ele == ojc[v])
      continue;

    //jest krawedzia wtorna
    low[v] = min(low[v], d[w]);
  }
  czy |= (s == v);
  if(d[v] and low[v] == d[v] and (s==-1 or czy))
    M.emplace(ojc[v]);
  return czy;
}

unordered_set <int> path(int a, int b, bool mosty = false)
{
  memset(odw, 0, sizeof(odw));
  memset(ojc, 0, sizeof(ojc));
  queue <int> Q;
  Q.push(a);
  odw[a] = true;
  ojc[a] = -1;
  while(!Q.empty())
  {
    int v = Q.front();
    Q.pop();
    for(auto ele : G[v])
    {
      if(mosty and M.find(ele) == M.end())
        continue;
      int w = drugi(ele, v);
      if(odw[w] == false)
      {
        odw[w] = true;
        ojc[w] = ele;
        Q.push(w);
      }
    }
  }
  unordered_set <int> RES;
  if(ojc[b] == 0)
    return RES;
  while(ojc[b] != -1)
  {
    RES.insert(ojc[b]);
    b = drugi(ojc[b], b);
  }
  return RES;
}

int main()
{
  int n, m;
  cin >> n >> m;
  int s, t;
  cin >> s >> t;
  for(int i=1; i<=m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    G[a].insert(i);
    G[b].insert(i);
    waga[i] = c;
    E.emplace_back(a,b);
  }
  unordered_set <int> P = path(s,t);
  if(P.empty())
  {
    cout << "0\n0\n\n";
    return 0;
  }
  int res = 2*INF;
  vector <int> W;
  memset(odw, 0, sizeof(odw));
  memset(ojc, 0, sizeof(ojc));
  tim = 0;
  dfs(s);
  int wyn = INF;
  for(auto ele : M)
    if(P.find(ele) != P.end())
      if(waga[ele] < res)
      {
        res = waga[ele];
        W = {ele};
      }
  for(auto ele : P)
  {
    M.clear();
    int p, q;
    tie(p,q) = E[ele];
    G[p].erase(ele);
    G[q].erase(ele);
    memset(odw, 0, sizeof(odw));
    memset(ojc, 0, sizeof(ojc));
    memset(low, 0, sizeof(low));
    memset(d, 0, sizeof(d));
    tim = 0;
    dfs(s, t);
    for(auto elf : M)
    {
      if(res > waga[ele] + waga[elf])
      {
        res = waga[ele] + waga[elf];
        W = {ele, elf};
      }
    }
    G[p].insert(ele);
    G[q].insert(ele);
  }
  if(res != 2*INF)
  {
    cout << res << "\n" << (int)W.size() << "\n";
    for(auto ele : W)
      cout << ele << " ";
    cout << "\n";
  }
  else
    cout << "-1\n";
}