//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

long long foo(vector <int> a)
{
  for(int i=0; i<6; i++)
    if(a[i] > 0 and a[(i+2)%6] > 0)
    {
      a[i]--;
      a[(i+1)%6]++;
      a[(i+2)%6]--;
      return 2*a[(i+1)%6] - 1 + foo(a);
    }
  //assert(false);
  return 0;
}

int main()
{
  vector <int> a(6);
  for(int i=0; i<6; i++)
    cin >> a[i];
  cout << foo(a) << "\n";
  return 0;
}