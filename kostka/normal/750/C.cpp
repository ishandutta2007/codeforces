//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector <pair <int, int> > X(n);
  for(int i=0; i<n; i++)
    cin >> X[i].first >> X[i].second;
  int dol = -2e9-7, gor = 2e9+7;
  if(X[0].second == 1)
    dol = 1900;
  else
    gor = 1899;
  for(int i=0; i<n; i++)
  {
    dol += X[i].first;
    gor += X[i].first;
    if(i+1 < n)
    {
      if(X[i+1].second == 1)
        dol = max(dol, 1900);
      else
        gor = min(gor, 1899);
    }
  }
  if(dol > gor)
    cout << "Impossible\n";
  else if(gor >= 1e9)
    cout << "Infinity\n";
  else
    cout << gor << "\n";
  return 0;
}