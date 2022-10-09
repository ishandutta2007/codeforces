//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int n, m, res = 1, zas = 0;

void kan(int a, int b)
{
  if(not(1 <= a and a <= n))
    return;
  if(b > zas)
  {
    res = a;
    zas = b;
  }
}

int main()
{
  cin >> n >> m;
  kan(m-1,m-1);
  kan(m+1,n-m);
  cout << res << "\n";
  return 0;
}