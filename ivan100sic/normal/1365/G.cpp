// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

basic_string<int> p[13];
ull o[13];
ull ans[1005];
int idxinv[1 << 13];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n;
  cin >> n;

  int idx = 0;
  for (int mask=0; mask<(1<<13); mask++) {
    if (__builtin_popcount(mask) == 5) {
      idx++;
      if (idx > n) {
        break;
      }
      idxinv[mask] = idx;
      for (int i=0; i<13; i++) {
        if (mask & (1 << i)) {
          p[i] += idx;
        }
      }
    }
  }

  for (int i=0; i<13; i++) {
    if (p[i].empty()) continue;

    cout << "? " << p[i].size();
    for (int x : p[i]) {
      cout << ' ' << x;
    }
    cout << '\n' << flush;
    cin >> o[i];
  }

  for (ull i=0; i<64; i++) {
    // koliko njih ima ovaj bit
    int c = 0, cmask = 0;
    ull mask = ull(1) << i;
    for (int j=0; j<13; j++) {
      if (mask & o[j]) {
        c++;
        cmask |= 1 << j;
      }
    }

    if (c == 5) {
      // javlja se jednom, pisi svima osim njemu
      for (int j=1; j<=n; j++) {
        if (j != idxinv[cmask]) {
          ans[j] |= mask;
        }
      }
    } else if (c > 5) {
      // bar dvaput, pisi svima
      for (int i=1; i<=n; i++) {
        ans[i] |= mask;
      }
    }
  }

  cout << '!';
  for (int i=1; i<=n; i++) {
    cout << ' ' << ans[i];
  }
  cout << '\n' << flush;
}