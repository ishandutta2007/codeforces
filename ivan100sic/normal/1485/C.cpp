// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll resi(int x, int bl, int br) {

  int ql = x / (bl + 1);
  int qr = x / (br + 1);

  if (ql == qr) {
    if (br < 40000) {
      ll z = 0;
      for (int b=bl; b<=br; b++) {
        z += min(b-1, ql);
      }
      return z;
    } else {
      return ql * (br-bl+1ll);
    }
  }

  int bm = (bl+br) / 2;
  return resi(x, bl, bm) + resi(x, bm+1, br);
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;

    cout << resi(x, 1, y) << '\n';
  }
}