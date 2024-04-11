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
#define ALL(x) x.begin(), x.end()

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

int main()
{
  ios_base::sync_with_stdio(0);
  string x, y;
  cin >> x >> y;
  reverse(ALL(x));
  reverse(ALL(y));
  for(int i=0; i<min(SZ(x),SZ(y)); i++) {
    if(x[i] != y[i]) {
      cout << SZ(x) + SZ(y) - 2*i << "\n";
      return 0;
    }
  }
  cout << SZ(x) + SZ(y) - 2 * min(SZ(x), SZ(y)) << "\n";
  return 0;
}