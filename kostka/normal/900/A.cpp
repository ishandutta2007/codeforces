//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  int a = 0, b = 0;
  for(int i=0; i<n; i++) {
    int x, y;
    cin >> x >> y;
    if(x < 0) a++;
    else b++;
  }
  if(min(a,b) <= 1)
    cout << "Yes\n";
  else
    cout << "No\n";

  return 0;
}