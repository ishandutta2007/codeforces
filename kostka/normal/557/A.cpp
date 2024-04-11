//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  int n;
  cin >> n;
  int a1, a2, b1, b2, c1, c2;
  cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
  int a, b, c;
  for(a = a2; a >= a1; a--)
    if(a+b1+c1 <= n)
      break;
  for(b = b2; b >= b1; b--)
    if(a+b+c1 <= n)
      break;
  for(c = c2; c >= c1; c--)
    if(a+b+c == n)
      break;
  cout << a << " " << b << " " << c << "\n";
  return 0;
}