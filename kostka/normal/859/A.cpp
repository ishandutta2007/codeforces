//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  int maxi = 0;
  for(int i=0; i<n; i++)
  {
    int x;
    cin >> x;
    maxi = max(maxi, x);
  }
  cout << max(0, maxi-25);
  return 0;
}