//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  int k;
  cin >> k;
  string res = "z";
  vector <int> w = {1};
  for(int i=2; i<=2000; i++)
    w.push_back(w.back() + i);
  int ix = (int)w.size()-1, e = 0;
  while(k)
  {
    while(w[ix] <= k)
    {
      k -= w[ix];
      for(int i=0; i<(ix+2); i++)
        res += ('a'+e);
      e++;
    }
    ix--;
  }
  cout << res << "\n";
  return 0;
}