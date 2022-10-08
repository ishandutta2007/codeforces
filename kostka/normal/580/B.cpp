//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  int n, d;
  cin >> n >> d;
  vector <pair <int, int>> X;
  for(int i=0; i<n; i++)
  {
    int a, b;
    cin >> a >> b;
    X.emplace_back(a,b);
  }
  sort(X.begin(), X.end());
  vector <long long> PREF = {0};
  long long ile = 0;
  for(int i=0; i<n; i++)
  {
    ile += X[i].second;
    PREF.push_back(ile);
  }
  long long res = 0;
  for(int i=0; i<n; i++)
  {
    int e = X[i].first + d;
    auto it = upper_bound(X.begin(), X.end(), make_pair(e,-1));
    int kt = (it - X.begin());
    res = max(res, PREF[kt] - PREF[i]);
  }
  cout << res << "\n";
  return 0;
}