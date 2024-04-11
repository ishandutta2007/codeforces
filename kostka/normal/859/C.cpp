//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for(int i=0; i<n; i++)
    cin >> a[i];
  a.push_back(0);
  reverse(a.begin(), a.end());
  vector <int> b = a;
  partial_sum(b.begin(), b.end(), b.begin());
  long long t = 0;
  for(int i=1; i<=n; i++)
    t = max(t, a[i] + b[i-1] - t);
  cout << b[n] - t << " " << t << "\n";
  return 0;
}