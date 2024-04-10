// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
vector<string> a;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n >> m;
  a.resize(n);
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }

  int x=0, y=0, z=0;
  while (1) {
    int f = 0;
    for (int d=0; d<=10 && !f; d++) {
      for (int i=0; i<=d; i++) {
        int u = x + i;
        int v = y + d - i;
        if (u < n && v < m && a[u][v] == '*') {
          z++;
          x = u;
          y = v;
          a[x][y] = '.';
          f = 1;
          break;
        }
      }
    }
    if (!f) {
      cout << z << '\n';
      return 0;
    }
  }
}