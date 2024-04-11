#include "bits/stdc++.h"

using namespace std;

bool special(string &x)
{
  for(auto lit : x)
    if(lit != 'a')
      return false;
  int n = (int)x.size();
  x[n-1] = 'z';
  return true;
}

int main()
{
  string x;
  cin >> x;
  int n = (int)x.size();
  if(not(special(x)))
  {
    int stan = 2;
    for(int i=0; i<n; i++)
    {
      if(stan>0 && x[i] != 'a')
      {
        x[i]--;
        stan = 1;
      }
      else if(stan == 1 and x[i] == 'a')
        stan = 0;
    }
  }
  cout << x << "\n";
}