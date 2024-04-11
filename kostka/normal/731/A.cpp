//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  char start = 'a';
  int wyn = 0;
  string x;
  cin >> x;
  for(auto lit : x)
  {
    int cur = lit - 'a';
    int pop = start - 'a';
    wyn += min((cur - pop + 26)%26, (pop - cur + 26)%26);
    start = lit;
  }
  cout << wyn << "\n";
  return 0;
}