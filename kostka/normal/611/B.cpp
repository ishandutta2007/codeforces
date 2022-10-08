//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

set <long long> S;

void add(vector <int> &E)
{
  long long x = 0;
  for(auto ele : E)
  {
    x *= 2;
    x += ele;
  }
  S.insert(x);
}

int main()
{
  vector <int> X;
  for(int i=1; i<=63; i++)
  {
    X.push_back(1);
    for(int j=1; j<(int)X.size(); j++)
    {
      X[j] = 0;
      add(X);
      X[j] = 1;
    }
  }
  vector <long long> VS;
  for(auto ele : S)
    VS.push_back(ele);
  long long a, b;
  cin >> a >> b;
  cout << upper_bound(VS.begin(), VS.end(), b) - upper_bound(VS.begin(), VS.end(), a-1) << "\n";
  return 0;
}