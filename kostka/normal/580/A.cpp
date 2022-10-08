//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector <int> V(n);
  vector <bool> X(n);
  for(int i=0; i<n; i++)
    cin >> V[i];
  for(int i=0; i<n-1; i++)
    if(V[i] <= V[i+1])
      X[i] = true;
  int res = 0;
  for(int i=0; i<n-1; i++)
    if(X[i] == true)
    {
      int ile = 1;
      while(i+1 < n-1 and X[i+1] == true)
      {
        i++;
        ile++;
      }
      res = max(res, ile);
    }
  cout << res + 1 << "\n";
  return 0;
}