#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    int p = 0;
    while (n%(2ll<<p) == 0) p++;
    if (n == 1ll<<p) {
      cout << -1 << endl;
    } else if ((n>>p) > 2ll<<p) {
      cout << (2ll<<p) << endl;
    } else {
      cout << (n>>p) << endl;
    }
  }
  /*
  for (int n = 2; n < 1000; n++) {
    int p = 0;
    while (n%(2<<p) == 0) p++;
    if (n == 1<<p) continue;
    if ((n>>p) > 2<<p) {
      int k = 2<<p;
      int base = k*(k+1)/2;
      assert((n-base)%k == 0);
      continue;
    }
    {
      int k = n>>p;
      int base = k*(k+1)/2;
      assert((n-base)%k == 0);
      continue;
    }
    int found = -1;
    for (int k = 2; found == -1; k++) {
      int base = k*(k+1)/2;
      if (base > n) break;
      if ((n-base)%k == 0) found = k;
    }
    cout << n << ' ' << found << endl;
  }*/
}