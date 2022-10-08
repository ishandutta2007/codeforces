//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

bool czy()
{
  int t, x, s;
  cin >> t >> s >> x;
  if(x >= t and (t%s == x%s))
    return true;
  if(x >= t+2 and ((t+1)%s == x%s))
    return true;
  return false;
}

int main()
{
  puts(czy() ? "YES" : "NO");
}