//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int ST = 20000;

bool validate(int stx)
{
  if(stx < 0 or stx > ST)
    return false;
  return true;
}

int main()
{
  int n;
  cin >> n;
  int stx = 0;
  for(int i=0; i<n; i++)
  {
    int ile;
    string gdz;
    cin >> ile >> gdz;
    if(stx == 0 and gdz != "South")
    {
      puts("NO");
      exit(0);
    }
    if(stx == ST and gdz != "North")
    {
      puts("NO");
      exit(0);
    }
    if(gdz == "South")
      stx += ile;
    if(gdz == "North")
      stx -= ile;
    if(!validate(stx))
    {
      puts("NO");
      exit(0);
    }
  }
  if(stx == 0)
    puts("YES");
  else
    puts("NO");
  return 0;
}