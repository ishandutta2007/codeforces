// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

// Terrible statement.
// Absolutely terrible.

int n;
int p[305][305], sol[305];
int rnk[305][305];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n;
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      cin >> p[i][j];
      rnk[i][p[i][j]] = j;
    }
  }

  for (int j=1; j<=n; j++) {
    cin >> p[0][j];
    rnk[0][p[0][j]] = j;
  }

  for (int i=1; i<=n; i++) {
    int pref = -1;
    sol[i] = -1;
    for (int j=1; j<=n; j++) {
      if (j == i) {
        continue;
      }

      if (pref == -1 || rnk[0][j] < rnk[0][pref]) {
        pref = j;
      }

      if (sol[i] == -1 || rnk[i][pref] < rnk[i][sol[i]]) {
        sol[i] = pref;
      }
    }
  }

  for (int i=1; i<=n; i++) {
    cout << sol[i] << " \n"[i == n];
  }
}