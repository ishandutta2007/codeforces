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
    ll a[4], z=0;
    for (int i=0; i<4; i++) {
      cin >> a[i];
    }

    sort(a, a+4);

    do {
      z = max(z, min(a[0], a[1]) * min(a[2], a[3]));
    } while (next_permutation(a, a+4));

    cout << z << '\n';
  }
}