//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  int ile = 0;
  int tim = 0;
  for(int i=1; i<=n; i++)
    if(tim + 5*i + k <= 240)
    {
      tim += 5*i;
      ile = i;
    }
  cout << ile << "\n";
  return 0;
}