//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  int r, x, y, nx, ny;
  cin >> r >> x >> y >> nx >> ny;
  double dx = abs(nx-x);
  double dy = abs(ny-y);
  double d = sqrt((dx*dx) + (dy*dy));
  cout << ceil(d/(2*r)) << "\n";
  return 0;
}