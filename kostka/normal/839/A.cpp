//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  int x = 0, y = 0;
  for(int i=0; i<n; i++)
  {
    int a;
    cin >> a;
    x += a;
    y += min(8, x);
    x -= min(8, x);
    if(y >= k)
    {
      cout << i+1 << "\n";
      return 0;
    }
  }
  cout << -1 << "\n";
  return 0;
}