//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  string x;
  cin >> x;
  x = 'A'+x+'A';
  vector <int> W;
  for(int i=0; i<(int)x.size(); i++)
  {
    char y = x[i];
    if(y == 'A' or y == 'E' or y == 'I' or y == 'O' or y == 'U' or y == 'Y')
      W.push_back(i);
  }
  int res = 0;
  for(int i=1; i<(int)W.size(); i++)
    res = max(W[i] - W[i-1], res);
  cout << res << "\n";
  return 0;
}