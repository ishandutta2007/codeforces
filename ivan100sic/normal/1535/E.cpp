// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int a[300005], c[300005];
int p[300005][20];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int q;
  cin >> q >> a[0] >> c[0];

  for (int i=1; i<=q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      cin >> p[i][0] >> a[i] >> c[i];
      for (int j=1; j<20; j++) {
        p[i][j] = p[p[i][j-1]][j-1];
      }
    } else {
      int v, w;
      cin >> v >> w;
      int b = 0;
      ll cost = 0;

      while (b < w && a[v] > 0) {
        int t = v;
        for (int i=19; i>=0; i--) {
          if (a[p[t][i]] > 0) {
            t = p[t][i];
          }
        }
        int amt = min(a[t], w - b);
        a[t] -= amt;
        b += amt;
        cost += amt * 1ll * c[t];
      }

      cout << b << ' ' << cost << '\n' << flush;
    }
  }
}