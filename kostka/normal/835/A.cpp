//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  int s, v1, v2, t1, t2;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  int w1 = s*v1 + 2*t1;
  int w2 = s*v2 + 2*t2;
  if(w1 == w2)
    cout << "Friendship\n";
  else if(w1 < w2)
    cout << "First\n";
  else
    cout << "Second\n";
  return 0;
}