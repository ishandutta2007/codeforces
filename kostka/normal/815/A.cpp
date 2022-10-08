//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 107;
int n, m;
int a[MAXN][MAXN];
int r[MAXN], c[MAXN];

const int INF = 1e9+7;

int check(int x, bool print = false)
{
  r[0] = x;
  for(int i=0; i<m; i++)
    c[i] = a[0][i] - r[0];
  for(int i=0; i<n; i++)
    r[i] = a[i][0] - c[0];
  for(int i=0; i<m; i++)
    if(c[i] < 0)
      return INF;
  for(int i=0; i<n; i++)
    if(r[i] < 0)
      return INF;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      if(a[i][j] != c[j] + r[i])
        return INF;
  int ile = 0;
  for(int i=0; i<m; i++)
    ile += c[i];
  for(int i=0; i<n; i++)
    ile += r[i];
  if(!print)
    return ile;
  cout << ile << "\n";
  for(int i=0; i<n; i++)
    while(r[i]--)
      cout << "row " << i+1 << "\n";
  for(int i=0; i<m; i++)
    while(c[i]--)
      cout << "col " << i+1 << "\n";
  return ile;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      cin >> a[i][j];
  int res = INF, ix = -1;
  for(int i=0; i<=500; i++)
  {
    int c = check(i);
    if(c < res)
    {
      res = c;
      ix = i;
    }
  }
  if(ix != -1)
    check(ix, true);
  else
    puts("-1");
  return 0;
}