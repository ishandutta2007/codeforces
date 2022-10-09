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
    string a, b;
    cin >> n >> a;

    for (char& x : a) x -= '0';

    b = string(n, 0);

    b[0] = 1;

    for (int i=1; i<n; i++) {
      int prev = a[i-1] + b[i-1];

      for (int x=2; x>=0; x--) {
        int w = x - a[i];
        if (w < 0 || w > 1 || x == prev) {
          continue;
        }
        b[i] = w;
        break;
      }
    }

    for (int i=0; i<n; i++) {
      cout << char(48 + b[i]);
    }
    cout << '\n';
  }
}