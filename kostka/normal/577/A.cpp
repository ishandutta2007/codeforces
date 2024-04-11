#include "bits/stdc++.h"

using namespace std;

int main()
{
  int n;
  cin >> n;
  int x;
  cin >> x;
  int ile = 0;
  for(int i=1; i<=n; i++)
    if(x % i == 0 and x/i <= n)
      ile++;
  cout << ile << "\n";
}