//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

bool prime(int a)
{
  for(int i=2; i*i<=a; i++)
    if(a % i == 0)
      return false;
  return true;
}

int main()
{
  int n;
  cin >> n;
  int i=0;
  while(++i)
    if(!prime(i*n+1))
    {
      cout << i << "\n";
      break;
    }
  return 0;
}