// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m, sx, sy;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n >> m >> sx >> sy;
  vector<int> rows(n);
  iota(begin(rows), end(rows), 1);
  swap(rows[0], rows[sx-1]);

  for (int i=0; i<n; i++) {
    int r = rows[i];

    vector<int> cols(m);
    iota(begin(cols), end(cols), 1);
    swap(cols[0], cols[sy-1]);

    for (int c : cols) {
      cout << r << ' ' << c << '\n';
      sy = c;
    }
  }
}