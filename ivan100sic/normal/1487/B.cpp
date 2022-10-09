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
    int n, k;
    cin >> n >> k;

    auto pr = [&](int x) {
      x %= n;
      if (x < 0) {
        x += n;
      }

      if (x == 0) {
        x = n;
      }

      cout << x << '\n';
    };

    if (n % 2) {
      int t = (n+1) / 2;
      int u = t - 1;

      pr((k+u-1)/u + k - 1);

    } else {
      pr(k);
    }
  }
}