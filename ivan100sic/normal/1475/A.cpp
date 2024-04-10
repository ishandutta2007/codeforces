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
    ll x;
    cin >> x;
    while (x % 2 == 0) x /= 2;
    cout << (x == 1 ? "NO\n" : "YES\n");
  }
}