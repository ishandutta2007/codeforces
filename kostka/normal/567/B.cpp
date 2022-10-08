//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

set <int> S;

int main()
{
  int n;
  cin >> n;
  int start = 0, res = 0;
  for(int i=0; i<n; i++)
  {
    char x;
    int y;
    cin >> x >> y;
    if(x=='+')
      S.insert(y);
    if(x=='-')
    {
      if(S.find(y) == S.end())
        start--;
      else
        S.erase(y);
    }
    res = max(res, (int)S.size()+start);
  }
  cout << res-start << "\n";
  return 0;
}