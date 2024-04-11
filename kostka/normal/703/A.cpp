#include "bits/stdc++.h"

using namespace std;

int main()
{
  int n;
  cin >> n;
  int ilex = 0, iley = 0;
  while(n--)
  {
    int x, y;
    cin >> x >> y;
    if(x > y)
      ilex++;
    if(x < y)
      iley++;
  }
  if(ilex > iley)
    puts("Mishka");
  else if(ilex == iley)
    puts("Friendship is magic!^^");
  else
    puts("Chris");
  return 0;
}