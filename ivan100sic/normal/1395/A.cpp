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
    ll r, g, b, w;
    cin >> r >> g >> b >> w;
    if (r%2+g%2+b%2+w%2 <= 1) {
      cout << "Yes\n";
    } else {
      if (r && g && b) {
        r--, g--, b--;
        w += 3;
        if (r%2+g%2+b%2+w%2 <= 1) {
          cout << "Yes\n";
        } else {
          cout << "No\n";
        }
      } else {
        cout << "No\n";
      }
    }
  }
}