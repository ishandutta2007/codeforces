// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int d[25][25];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;

    int u = a.size(), v = b.size();
    memset(d, 0, sizeof d);

    int z = 0;
    for (int i=u-1; i>=0; i--) {
      for (int j=v-1; j>=0; j--) {
        d[i][j] = a[i] == b[j] ? d[i+1][j+1] + 1 : 0;
        z = max(z, d[i][j]);
      }
    }

    cout << u+v-2*z << '\n';
  }
}