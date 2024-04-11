//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  int a, b;
  cin >> a >> b;
  long long x = 1;
  for(int i=1; i<=min(a,b); i++)
    x *= i;
  cout << x << "\n";
  return 0;
}