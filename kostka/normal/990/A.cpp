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
  ll n, m, a, b;
  cin >> n >> m >> a >> b;
  ll x = n/m*m;
  ll y = x+m;
  ll minus = y-n;
  ll plus = n-x;
  cout << min(a * minus, b * plus) << "\n";
  return 0;
}