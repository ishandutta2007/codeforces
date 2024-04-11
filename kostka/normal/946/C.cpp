//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

int main()
{
  ios_base::sync_with_stdio(0);
  string x;
  cin >> x;
  char let = 'a';
  for(int i=0; i<SZ(x); i++)
  {
    if(x[i] <= let) {
      x[i] = let++;
    }
    if(let > 'z') {
      cout << x << "\n";
      return 0;
    }
  }
  cout << -1 << "\n";
  return 0;
}