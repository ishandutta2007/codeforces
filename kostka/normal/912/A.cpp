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
  long long x, y, z;
  cin >> x >> y >> z;
  a -= 2*x;
  a -= y;
  b -= y;
  b -= 3*z;
  long long res = -min(0LL, a) - min(0LL, b);
  cout << res << "\n";
  return 0;
}