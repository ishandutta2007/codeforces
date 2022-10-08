#include "bits/stdc++.h"

using namespace std;

const int MAXN = 200007;
int uni[MAXN];
vector <pair <int, int>> G[MAXN];
bool odw[MAXN];

int n, k;
long long res = 0;

void dfs(int v)
{
  odw[v] = true;
  for(auto ele : G[v])
  {
    int w, waga;
    tie(w, waga) = ele;
    if(odw[w] == false)
    {
      dfs(w);
      uni[v] += uni[w];
      res += waga * min(uni[w], k-uni[w]);
    }
  }
}

int main()
{
  cin >> n >> k;
  k *= 2;
  for(int i=0; i<k; i++)
  {
    int x;
    cin >> x;
    uni[x] = 1;
  }
  for(int i=2; i<=n; i++)
  {
    int a, b;
    cin >> a >> b;
    G[a].emplace_back(b,1);
    G[b].emplace_back(a,1);
  }
  dfs(1);
  cout << res << "\n";
}