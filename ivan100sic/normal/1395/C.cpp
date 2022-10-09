// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

bool d[205][512];
int a[205], b[205];
int n, m;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  d[0][0] = 1;
  cin >> n >> m;
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }
  for (int j=0; j<m; j++) {
    cin >> b[j];
  }

  for (int i=0; i<n; i++) {
    for (int x=0; x<512; x++) {
      if (d[i][x]) {
        for (int j=0; j<m; j++) {
          d[i+1][x|(a[i] & b[j])] = 1;
        }
      }
    }
  }

  cout << find(d[n], d[n]+512, true) - d[n] << '\n';
}