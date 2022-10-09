// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
int a[505][505];
const int b = 720720;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n >> m;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      cin >> a[i][j];
    }
  }

  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      int x, v = a[i][j];
      if ((i+j) % 2 == 0) {
        x = b;
      } else {
        x = b + v*v*v*v;
      }

      cout << x << " \n"[j == m-1];
    }
  }
}