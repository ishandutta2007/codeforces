//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  int n, p, q, r;
  cin >> n >> p >> q >> r;
  vector <int> a(n), minil(n), minir(n), maxil(n), maxir(n);
  for(int i=0; i<n; i++)
    cin >> a[i];
  minil[0] = maxil[0] = a[0];
  minir[n-1] = maxir[n-1] = a[n-1];
  for(int i=1; i<n; i++)
  {
    minil[i] = min(minil[i-1], a[i]);
    maxil[i] = max(maxil[i-1], a[i]);
  }
  for(int i=n-2; i>=0; i--)
  {
    minir[i] = min(minir[i+1], a[i]);
    maxir[i] = max(maxir[i+1], a[i]);
  }
  long long res = 1LL * p * a[0] + 1LL * q * a[0] + 1LL * r * a[0];
  for(int i=0; i<n; i++)
  {
    res = max(res, 1LL * p * maxil[i] + 1LL * q * a[i] + 1LL * r * maxir[i]);
    res = max(res, 1LL * p * minil[i] + 1LL * q * a[i] + 1LL * r * maxir[i]);
    res = max(res, 1LL * p * maxil[i] + 1LL * q * a[i] + 1LL * r * minir[i]);
    res = max(res, 1LL * p * minil[i] + 1LL * q * a[i] + 1LL * r * minir[i]);
  }
  cout << res << "\n";
  return 0;
}