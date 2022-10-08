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
  sort(a.begin(), a.end());
  int ile = 0;
  for(int i=0; i<n; i++)
    if(a[i] != a[0] and a[i] != a.back())
      ile++;
  cout << ile << "\n";
  return 0;
}