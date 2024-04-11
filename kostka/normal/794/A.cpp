//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  int a, b, c, n;
  cin >> a >> b >> c >> n;
  int ile = 0;
  for(int i=1; i<=n; i++)
  {
    int x;
    cin >> x;
    if(b < x and x < c)
      ile++;
  }
  cout << ile << "\n";
  return 0;
}