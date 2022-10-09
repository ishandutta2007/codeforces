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
    int n;
    cin >> n;
    string ok = "YES";
    ll last = -1, pass = 0, x;
    for (int i=0; i<n; i++) {
      cin >> x;
      x += pass;
      if (x <= last) {
        ok = "NO";
      } else {
        pass = x - last - 1;
        last++;
      }
    }

    cout << ok << '\n';
  }
}