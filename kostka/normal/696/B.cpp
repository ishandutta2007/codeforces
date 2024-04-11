//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100007;
bool czy[MAXN];
int pod[MAXN], nad[MAXN];
vector <int> G[MAXN];

void dfs(int v, int d = 0)
{
  pod[v] = 1;
  nad[v] = d;
  czy[v] = true;
  for(auto w : G[v])
    if(czy[w] == false)
    {
      dfs(w, d+1);
      pod[v] += pod[w];
    }
}

int main()
{
  int n;
  cin >> n;
  for(int i=2; i<=n; i++)
  {
    int x;
    cin >> x;
    G[x].push_back(i);
    G[i].push_back(x);
  }
  dfs(1);
  for(int i=1; i<=n; i++)
  {
    //cerr << pod[i] << " " << nad[i] << "\n";
    cout << 1 + nad[i] + 0.5 * (n - nad[i] - pod[i]) << " ";
  }
  cout << "\n";
  return 0;
}