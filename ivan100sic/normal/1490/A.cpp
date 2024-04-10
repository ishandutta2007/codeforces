// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int r(int x, int y) {
  int z = 0;
  if (x > y) {
    swap(x, y);
  }
  while (y > 2*x) {
    x *= 2;
    z++;
  }
  return z;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n, z=0;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
      cin >> a[i];
    }

    for (int i=1; i<n; i++) {
      z += r(a[i], a[i-1]);
    }

    cout << z << '\n';
  }
}