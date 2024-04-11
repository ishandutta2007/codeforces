//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 200007;
vector <int> G[MAXN];
int col[MAXN], vis[MAXN], ile;

void color(int v, int c = -1)
{
  vis[v] = true;
  int cr = 0;
  for(auto w : G[v])
    if(vis[w] == 0)
    {
      cr = (cr+1)%ile;
      while(cr == col[v] or cr == c)
        cr = (cr+1)%ile;
      col[w] = cr;
      color(w, col[v]);
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i=1; i<n; i++)
  {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for(int i=1; i<=n; i++)
    ile = max(ile, (int)G[i].size() + 1);
  cout << ile << "\n";
  for(int i=1; i<=n; i++)
    if((int)G[i].size()+1 == ile)
      color(i);
  for(int i=1; i<=n; i++)
    cout << col[i]+1 << " ";
  cout << "\n";
  return 0;
}