//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100007;
int a[MAXN], b[MAXN];

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for(int i=0; i<m; i++)
    cin >> a[i] >> b[i];
  int roz = 1e9 + 7;
  for(int i=0; i<m; i++)
    roz = min(roz, b[i]-a[i]+1);
  cout << roz << "\n";
  for(int i=0; i<n; i++)
    cout << i%roz << " ";
  cout << "\n";
  return 0;
}