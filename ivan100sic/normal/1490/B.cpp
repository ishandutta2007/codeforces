// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int resi(int* c) {
  int k = accumulate(c, c+3, 0) / 3, z = 0;

  int d[4];
  copy(c, c+3, d);

  for (int i=0; i<3; i++) {
    if (d[i] < k) {
      return 1e9;
    }
    z += d[i] - k;
    d[i+1] += d[i] - k;
    d[i] = k;
  }

  return z;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n, c[3] = {0};
    cin >> n;
    for (int i=0; i<n; i++) {
      int x;
      cin >> x;
      c[x%3]++;
    }

    int z = 1e9;

    for (int i=0; i<3; i++) {
      z = min(z, resi(c));
      rotate(c, c+1, c+3);
    }

    cout << z << '\n';
  }
}