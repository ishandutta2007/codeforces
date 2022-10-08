//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9+7;

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector <long long> X(n);
  for(int i=0; i<n; i++)
    cin >> X[i];
  sort(X.begin(), X.end());
  vector <long long> PREF(n), DWA(n);
  for(int i=n-2; i>=0; i--)
    PREF[i] = (2LL * PREF[i+1] + X[i+1]) % MOD;
  DWA[0] = 1;
  for(int i=1; i<n; i++)
    DWA[i] = (2 * DWA[i-1]) % MOD;
  long long res = 0;
  for(int i=0; i<n-1; i++)
  {
    res += PREF[i] - (X[i] * (DWA[n-i-1] - 1));
    res = ((res%MOD)+MOD)%MOD;
  }
  cout << res << "\n";
  return 0;
}