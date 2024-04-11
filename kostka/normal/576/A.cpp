//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

bool prime(int a)
{
  for(int i=2; i*i <= a; i++)
    if(a%i==0)
      return false;
  return true;
}

int main()
{
  int n;
  cin >> n;
  vector <int> X;
  for(int i=2; i<=n; i++)
    if(prime(i))
      X.push_back(i);
  auto W = X;
  for(auto ele : X)
  {
    int q = ele;
    while(q * ele <= n)
      W.push_back(q *= ele);
  }
  cout << (int)W.size() << "\n";
  for(auto ele : W)
    cout << ele << " ";
  return 0;
}