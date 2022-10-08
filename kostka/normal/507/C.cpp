//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

vector <long long> V;

void go(long long a)
{
  if(a==0)
    return;
  V.push_back(a);
  go(a/2);
}

int main()
{
  int h;
  long long n;
  cin >> h >> n;
  go((1LL<<h)+n-1);
  reverse(V.begin(), V.end());
  long long res = 0;
  bool lewo = true;
  for(int i=0; i+1<(int)V.size(); i++)
  {
    //cerr << res << "\n";
    if(2*V[i]==V[i+1])
    {
      if(lewo)
      {
        lewo = false;
        res += 1;
      }
      else
        res += (1LL<<(h-i));
    }
    else
    {
      if(lewo)
        res += (1LL<<(h-i));
      else
      {
        lewo = true;
        res += 1;
      }
    }
  }
  cout << res << "\n";
  return 0;
}