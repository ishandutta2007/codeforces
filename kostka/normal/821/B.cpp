//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

long long check(int x, int y)
{
  long long a = (1LL * x * (x+1)) / 2 * (y+1);
  long long b = (1LL * y * (y+1)) / 2 * (x+1);
  //cerr << x << " " << y << " " << a << " " << b << "\n";
  return a+b;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int m, b;
  cin >> m >> b;
  long long res = 0;
  for(int i=0; i<=m*b; i++)
  {
    int x = i;
    int y = -1.0*x/m + b;
    res = max(res, check(x,y));
  }
  cout << res << "\n";
}