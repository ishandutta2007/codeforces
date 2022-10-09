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
    ll n, m, x;
    cin >> n >> m >> x;
    x--;
    ll c = x / n;
    ll r = x % n;

    cout << r*m + c + 1 << '\n';
  }
}