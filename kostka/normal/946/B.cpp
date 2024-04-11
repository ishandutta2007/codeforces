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
  long long a, b;
  cin >> a >> b;
  while(true) {
    // cerr << a << " " << b << "\n";
    if(a == 0 or b == 0) break;
    if(a >= 2*b) {
      a %= 2*b;
      continue;
    }
    if(b >= 2*a) {
      b %= 2*a;
      continue;
    }
    break;
  }
  cout << a << "  " << b << "\n";
  return 0;
}