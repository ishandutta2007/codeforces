// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int a[505], n, x;
short d[505][505][505];

template<class T>
void mn(T& x, T y) {
  x = min(x, y);
}

void cl() {
  for (int i=0; i<=n+1; i++) {
    for (int j=0; j<=501; j++) {
      memset(d[i][j], 63, sizeof d[0][0]);
    }
  }
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> x;
    for (int i=0; i<n; i++) {
      cin >> a[i];
    }

    cl();

    d[0][0][x] = 0;
    for (int i=0; i<n; i++) {
      for (int j=0; j<=500; j++) {
        for (int k=0; k<=500; k++) {
          if (a[i] >= j) {
            // idi bez menjanja
            mn(d[i+1][a[i]][k], d[i][j][k]);
          }

          // zameni za x
          if (j <= k && j < a[i]) {
            mn(d[i+1][k][a[i]], (short)(d[i][j][k] + 1));
          }
        }
      }
    }

    short z = 1000;
    for (int j=0; j<=500; j++) {
      for (int k=0; k<=500; k++) {
        mn(z, d[n][j][k]);
      }
    }

    if (z == 1000) {
      z = -1;
    }

    cout << z << '\n';
  }
}