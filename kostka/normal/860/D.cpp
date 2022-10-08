//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 200007;
vector <int> G[MAXN];
vector <tuple <int, int, int> > res;
int pre[MAXN], tim;

// TODO: doda to w kocu do biblioteczki
bool dfs(int v, int anc = 0)
{
  pre[v] = ++tim;
  vector <int> t;
  for(auto w : G[v])
    if(pre[w] > pre[v] or (!pre[w] and !dfs(w, v)))
        t.push_back(w);
  for(int i=0; i+1<(int)t.size(); i+=2)
    res.emplace_back(t[i], v, t[i+1]);
  if(anc and t.size() % 2)
  {
    res.emplace_back(t.back(), v, anc);
    return true;
  }
  else
    return false;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  while(m--)
  {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for(int i=1; i<=n; i++)
    if(!pre[i])
      dfs(i);
  cout << (int)res.size() << "\n";
  for(auto& r : res)
    cout << get<0>(r) << " " << get<1>(r) << " " << get<2>(r) << "\n";
  return 0;
}