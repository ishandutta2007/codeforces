//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  long long n;
  cin >> n;
  long long res = 0;
  long long ile = 0;
  for(int i=1; ile <= n; i++)
  {
    ile *= 10;
    ile += 9;
    res += (min(ile, n)-ile/10) * i;
  }
  cout << res << "\n";
  return 0;
}