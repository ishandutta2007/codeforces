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
    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;
    int u = count(begin(s), end(s), 'U');
    int d = count(begin(s), end(s), 'D');
    int l = count(begin(s), end(s), 'L');
    int r = count(begin(s), end(s), 'R');

    bool kx, ky;

    if (x < 0) {
      kx = l >= -x;
    } else {
      kx = r >= x;
    }

    if (y < 0) {
      ky = d >= -y;
    } else {
      ky = u >= y;
    }

    cout << (kx && ky ? "YES\n" : "NO\n");
  }
}