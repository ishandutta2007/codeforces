#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    array<int, 3> c;
    cin >> c[0] >> c[1] >> c[2];
    array<int, 5> a;
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
    cout << ([&]() -> bool {
      for (int i : {0, 1, 2}) {
        if (a[i] > c[i]) return false;
        c[i] -= a[i];
      }
      {
        int t = min(c[0], a[3]);
        c[0] -= t;
        a[3] -= t;
      }
      {
        int t = min(c[1], a[4]);
        c[1] -= t;
        a[4] -= t;
      }
      return a[3] + a[4] <= c[2];
    }()
                          ? "YES\n"
                          : "NO\n");
  }
}