//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

  string x;
  int n;

bool skok(int a, int b)
{
  for(int i=0; i<5; i++)
  {

    if(a+i*b >= n)
      return false;
    if(x[a+i*b] == '.')
      return false;
  }
  return true;
}

int main()
{
  cin >> n;
  cin >> x;
  for(int i=0; i<n; i++)
    for(int j=1; j<n; j++)
      if(skok(i,j))
      {
        puts("yes");
        return 0;
      }
  puts("no");
  return 0;
}