//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100007;
long long d[MAXN], h[MAXN];

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i=1; i<=m; i++)
    cin >> d[i] >> h[i];
  d[0] = 1;
  h[0] = h[1]+d[1]-1;
  d[m+1] = n;
  h[m+1] = h[m]+n-d[m];
  for(int i=0; i<=m; i++)
    if(abs(h[i+1]-h[i]) > d[i+1]-d[i])
    {
      puts("IMPOSSIBLE");
      return 0;
    }
  long long maks = 0;
  for(int i=0; i<=m+1; i++)
    maks = max(maks, h[i]);
  for(int i=0; i<=m; i++)
  {
    int ch = d[i+1]-d[i]-abs(h[i+1]-h[i]);
    maks = max(maks, max(h[i+1], h[i])+ch/2);
  }
  cout << maks << "\n";
  return 0;
}