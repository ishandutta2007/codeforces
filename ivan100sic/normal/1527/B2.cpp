// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

map<tuple<int, int, int, int>, int> wn;

int winner(int p, int s, int c, int r) {
  if (wn.count({p, s, c, r})) {
    return wn[{p, s, c, r}];
  }

  int& z = wn[{p, s, c, r}];
  z = 1e9;

  // game end?
  if (!p && !s && !c) {
    z = 0;
    return 0;
  }

  // reverse?
  if (r == 0 && s > 0) {
    z = min(z, -winner(p, s, c, 1));
  }

  // centar?
  if (c > 0) {
    z = min(z, 1-winner(p, s, c-1, 0));
  }

  // pair
  if (p > 0) {
    z = min(z, 1-winner(p-1, s+1, c, 0));
  }

  // single?
  if (s > 0) {
    z = min(z, 1-winner(p, s-1, c, 0));
  }

  return z;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n;
    string a;
    cin >> n >> a;
    int c = n % 2 == 1 && a[n/2] == '0';
    int p = 0, s = 0;
    for (int i=0; i<n/2; i++) {
      int k = a[i] == '0';
      k += a[n-1-i] == '0';
      if (k == 1) s++;
      else if (k == 2) p++;
    }

    int z = winner(p, s, c, 0);
    if (z < 0) cout << "ALICE\n";
    else if (z == 0) cout << "DRAW\n";
    else cout << "BOB\n";
  }
}