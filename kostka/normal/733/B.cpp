//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector <int> L(n), R(n);
  int odp = 0;
  for(int i=0; i<n; i++)
    cin >> L[i] >> R[i];
  long long sumL = 0, sumR = 0;
  for(int i=0; i<n; i++)
  {
    sumL += L[i];
    sumR += R[i];
  }
  long long best = abs(sumL-sumR);
  for(int i=0; i<n; i++)
  {
    int newL = sumL - L[i] + R[i];
    int newR = sumR - R[i] + L[i];
    if(abs(newL - newR) > best)
    {
      best = abs(newL - newR);
      odp = i+1;
    }
  }
  cout << odp << "\n";
  return 0;
}