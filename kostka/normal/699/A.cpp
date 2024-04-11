//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int INF = 1e9 + 7;

int main()
{
  int n;
  cin >> n;
  string x;
  cin >> x;
  vector <int> t(n);
  for(int i=0; i<n; i++)
    cin >> t[i];
  int res = INF;
  for(int i=1; i<n; i++)
    if(x[i] == 'L' and x[i-1] == 'R')
      res = min(res, (t[i]-t[i-1])/2);
  if(res == INF)
    res = -1;
  cout << res << "\n";
  return 0;
}