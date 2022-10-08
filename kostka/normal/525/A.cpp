//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  int n;
  multiset <char> S;
  cin >> n;
  int wyn = 0;
  for(int i=0; i<n-1; i++)
  {
    char a, b;
    cin >> a;
    S.insert(a - 'a' + 'A');
    cin >> b;
    if(S.find(b) == S.end())
      wyn++;
    else
      S.erase(S.find(b));
  }
  cout << wyn;
  return 0;
}