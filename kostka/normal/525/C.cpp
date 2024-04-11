//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int ile[1000007];

int main()
{
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
  {
    int a;
    cin >> a;
    ile[a]++;
  }
  vector <int> X;
  for(int i=1000000; i>=1; i--)
  {
    while(ile[i] >= 2)
    {
      X.push_back(i);
      ile[i] -= 2;
    }
    if((ile[i] == 1) and (ile[i-1] > 0))
    {
      X.push_back(i-1);
      ile[i]--;
      ile[i-1]--;
    }
  }
  long long wyn = 0;
  for(int i=0; i+1<X.size(); i+=2)
    wyn += 1LL*X[i]*X[i+1];
  cout << wyn << "\n";
  return 0;
}