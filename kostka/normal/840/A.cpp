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
  vector <pair <int, int> > X;
  for(int i=0; i<n; i++)
  {
    int x;
    cin >> x;
    X.push_back(make_pair(-x, i));
  }
  sort(X.begin(), X.end());
  sort(a.begin(), a.end());
  vector <int> r(n);
  for(int i=0; i<n; i++)
    r[X[i].second] = a[i];
  for(int i=0; i<n; i++)
    cout << r[i] << " ";
  cout << "\n";
  return 0;
}