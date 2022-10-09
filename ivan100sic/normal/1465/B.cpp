// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

bool fair(ll x) {
  ll t = x;
  vector<int> c(10);
  while (t) {
    c[t%10] = 1;
    t /= 10;
  }

  for (int i=1; i<10; i++) {
    if (c[i]) {
      if (x % i) return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    ll x;
    cin >> x;
    while (!fair(x)) x++;
    cout << x << '\n';
  }
}