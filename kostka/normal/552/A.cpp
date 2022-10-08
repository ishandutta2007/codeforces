//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  int n;
  cin >> n;
  long long res = 0;
  while(n--)
  {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    res += (c-a+1)*(d-b+1);
  }
  cout << res << "\n";
  return 0;
}