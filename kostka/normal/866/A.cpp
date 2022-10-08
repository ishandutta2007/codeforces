//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  int res = 0;
  if(n == 1)
    res = 1;
  else
    res = 2*(n-1);
  cout << res << " " << 2 << "\n" << 1 << " " << 2 << "\n";
  return 0;
}