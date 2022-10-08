//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 507;
int p[MAXN][MAXN], d[MAXN][MAXN];
char tab[MAXN][MAXN];

int sumap(int a, int b, int c, int e)
{
  return p[c][e] - p[c][b-1] - p[a-1][e] + p[a-1][b-1];
}

int sumad(int a, int b, int c, int e)
{
  return d[c][e] - d[c][b-1] - d[a-1][e] + d[a-1][b-1];
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for(int i=0; i<n; i++)
    cin >> tab[i];
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
    {
      if(tab[i][j] == '.' and tab[i][j+1] == '.')
        p[i+1][j+1] = 1;
      if(tab[i][j] == '.' and tab[i+1][j] == '.')
        d[i+1][j+1] = 1;
    }
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
    {
      p[i][j] += p[i][j-1] + p[i-1][j] - p[i-1][j-1];
      d[i][j] += d[i][j-1] + d[i-1][j] - d[i-1][j-1];
    }
  int q;
  cin >> q;
  while(q--)
  {
    int a, b, c, e;
    cin >> a >> b >> c >> e;
    int w1 = sumap(a, b, c, e-1);
    int w2 = sumad(a, b, c-1, e);
    cout << w1 + w2 << "\n";
  }
  return 0;
}