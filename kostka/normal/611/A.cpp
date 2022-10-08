//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  vector <int> W = {52, 52, 52, 52, 53, 53, 52};
  map <int, int> M = {{30, 11}, {31, 7}};
  int x;
  string y, z;
  cin >> x >> y >> z;
  if(z == "week")
    cout << W[x-1] << "\n";
  else
  {
    if(M[x] == 0)
      cout << 12 << "\n";
    else
      cout << M[x] << "\n";
  }
  return 0;
}