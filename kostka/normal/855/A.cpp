//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  set <string> S;
  for(int i=0; i<n; i++)
  {
    string x;
    cin >> x;
    if(S.find(x) == S.end())
      puts("NO");
    else
      puts("YES");
    S.insert(x);
  }
  return 0;
}