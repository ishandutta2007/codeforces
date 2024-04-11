#include "bits/stdc++.h"

using namespace std;

void test()
{
  int n, k;
  cin >> n >> k;
  int wyn = 0;
  for(int i=1; i<n; i++)
  {
    int x;
    cin >> x;
    wyn += x;
  }
  int guess = (((k-1)%n - (wyn)%n)%n+n)%n;
  cout << guess + 1 << "\n";
}

int main()
{
  int t;
  cin >> t;
  while(t--)
    test();
}