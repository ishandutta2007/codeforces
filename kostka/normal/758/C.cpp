//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

long long tab[107][107];

int main()
{
  int n, m;
  long long k;
  int x, y;
  cin >> n >> m >> k >> x >> y;
  int cykl = 0;
  for(int i=1; i<=n; i++)
    cykl += m;
  for(int i=n-1; i>=2; i--)
    cykl += m;
  long long ile = k / cykl;
  long long reszta = k % cykl;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
      if(reszta)
      {
        tab[i][j]++;
        reszta--;
      }
  for(int i=n-1; i>=2; i--)
    for(int j=1; j<=m; j++)
      if(reszta)
      {
        tab[i][j]++;
        reszta--;
      }
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
      tab[i][j] += ile;
  for(int i=n-1; i>=2; i--)
    for(int j=1; j<=m; j++)
      tab[i][j] += ile;
  long long mini = tab[1][1], maxi = tab[1][1];
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
    {
      mini = min(tab[i][j], mini);
      maxi = max(tab[i][j], maxi);
    }
  cout << maxi << " " << mini << " " << tab[x][y] << "\n";
  return 0;
}