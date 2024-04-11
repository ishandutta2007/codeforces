//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  int n, a, b;
  cin >> n >> a >> b;
  a--;
  for(int i=0; i<abs(b); i++)
    a = (a+(b/abs(b))+n)%n;
  cout << a+1 << "\n";
  return 0;
}