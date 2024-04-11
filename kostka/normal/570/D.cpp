//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 500007;
vector <int> G[MAXN];
vector <pair <int, int>> D[MAXN];

int tim;
int pre[MAXN], post[MAXN];
bool czy[MAXN][26];
bool zap[26];

void dfs(int v, int d = 1)
{
  pre[v] = ++tim;
  D[d].emplace_back(tim, v);
  for(auto w : G[v])
    if(pre[w] == 0)
      dfs(w,d+1);
  post[v] = ++tim;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  for(int i=2; i<=n; i++)
  {
    int a;
    cin >> a;
    G[a].push_back(i);
  }
  string w;
  cin >> w;
  w = "#"+w;
  dfs(1);
  for(int i=1; i<=n; i++)
  {
    int las = -1;
    for(int j=0; j<(int)D[i].size(); j++)
    {
      int v = D[i][j].second;
      if(las != -1)
        for(int k=0; k<26; k++)
          czy[v][k] = czy[las][k];
      int z = w[v]-'a';
      czy[v][z] = !czy[v][z];
      las = v;
    }
  }
  while(q--)
  {
    int a, b;
    cin >> a >> b;
    for(int i=0; i<26; i++)
      zap[i] = false;
    auto it = upper_bound(D[b].begin(), D[b].end(), make_pair(pre[a],0));
    if(it != D[b].begin())
    {
      it--;
      int e = (*it).second;
      for(int i=0; i<26; i++)
        zap[i] ^= czy[e][i];
    }
    it = lower_bound(D[b].begin(), D[b].end(), make_pair(post[a],0));
    if(it != D[b].begin())
    {
      it--;
      int e = (*it).second;
      for(int i=0; i<26; i++)
        zap[i] ^= czy[e][i];
    }
    int ile = 0;
    for(int i=0; i<26; i++)
      if(zap[i] == 1)
        ile++;
    if(ile <= 1)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}