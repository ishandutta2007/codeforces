//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

long long pole(int a, int b)
{
  return 2*(a+b);
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  long long res = pole(1, n);
  for(int i=1; i<=n; i++)
    res = min(res, pole(i, (n+i-1)/i));
  cout << res << "\n";
  return 0;
}