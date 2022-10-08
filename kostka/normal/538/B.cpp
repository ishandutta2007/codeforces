//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

vector <int> X;

int main()
{
  string x;
  cin >> x;
  int n = x.size();
  int ile = 1;
  for(int i=n-1; i>=0; i--)
  {
    for(int j=0; j<x[i]-'0'; j++)
    {
      //cerr << i << " " << j << "\n";
      if((int)X.size() == j)
        X.push_back(ile);
      else
        X[j] += ile;
    }
    ile *= 10;
  }
  cout << (int)X.size() << "\n";
  for(auto ele : X)
    cout << ele << " ";
  cout << "\n";
  return 0;
}