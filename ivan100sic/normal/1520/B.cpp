// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    ll n, z=0;
    cin >> n;
    for (ll x=1; x<1e15; x = 10*x+x%10) {
      for (ll y=1; y<=9; y++) {
        if (x*y <= n) {
          z++;
        }
      }
    }

    cout << z << '\n';
  }
}