//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  int n;
  cin >> n;
  if(n<=2)
  {
    cout << "1\n1\n";
    return 0;
  }
  if(n==3)
  {
    cout << "2\n1 3\n";
    return 0;
  }
  vector <int> A = {4, 2}, B = {1, 3};
  for(int i=5; i<=n; i++)
  {
    if(i%2)
      A.push_back(i);
    else
      B.push_back(i);
  }
  reverse(A.begin(), A.end());
  cout << n << "\n";
  for(auto ele : A)
    cout << ele << " ";
  for(auto ele : B)
    cout << ele << " ";
  cout << "\n";
  return 0;
}