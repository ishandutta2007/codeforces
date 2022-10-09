// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int ask(int l, int r) {
  int x;
  cout << "? " << l << ' ' << r << '\n' << flush;
  cin >> x;
  return x;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n, t;
  cin >> n >> t;
  while (t--) {
    int k;
    cin >> k;
    int l = 1, r = n - 1, o = n;
    while (l <= r) {
      int m = (l + r) / 2;
      int x = ask(1, m);
      if (m-x >= k) {
        o = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    cout << "! " << o << '\n' << flush;
  }
}