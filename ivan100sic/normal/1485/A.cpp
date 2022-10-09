// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int st(int a, int b) {
  int z = 0;
  if (b == 1) return 1e9;
  while (a > 0) {
    a /= b;
    z++;
  }
  return z;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;

    int w = 1e9;
    for (int i=0; i<=40; i++) {
      w = min(w, i + st(a, b+i));
    }

    cout << w << '\n';
  }
}
//ff