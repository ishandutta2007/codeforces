//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 107;
int wyn[MAXN];

int main()
{
  int n, m;
  cin >> n >> m;
  vector <pair <int, int>> V, W;
  for(int i=0; i<m; i++)
  {
    V.clear();
    for(int j=1; j<=n; j++)
    {
      int a;
      cin >> a;
      V.emplace_back(a,-j);
    }
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    wyn[-V[0].second]++;
  }
  for(int i=1; i<=n; i++)
    W.emplace_back(wyn[i],-i);
  sort(W.begin(), W.end());
  reverse(W.begin(), W.end());
  cout << -W[0].second << "\n";
  return 0;
}