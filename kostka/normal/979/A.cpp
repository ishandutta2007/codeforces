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
  ll x;
  cin >> x;
  x++;
  if(x == 1) {
    cout << 0 << "\n";
  } else if(x & 1) {
    cout << x << "\n";
  } else {
    cout << x/2 << "\n";
  }
}