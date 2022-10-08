//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector <int> a(n);
  for(int i=0; i<n; i++)
    cin >> a[i];
  int maks = *max_element(a.begin(), a.end());
  long long res = 0;
  for(int i=0; i<n; i++)
    res += maks - a[i];
  cout << res << "\n";
  return 0;
}