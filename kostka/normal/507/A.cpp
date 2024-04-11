//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  vector <pair <int, int>> A = {{20000,-1}};
  for(int i=0; i<n; i++)
  {
    int a;
    cin >> a;
    A.push_back({a,i});
  }
  sort(A.begin(), A.end());
  int sum = 0;
  for(int i=0; i<=n; i++)
  {
    sum += A[i].first;
    if(sum > k)
    {
      cout << i << "\n";
      for(int j=0; j<i; j++)
        cout << A[j].second+1 << " ";
      cout << "\n";
      return 0;
    }
  }
  return 0;
}