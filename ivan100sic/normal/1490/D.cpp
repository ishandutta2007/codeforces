// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

void resi(int l, int r, vector<int>& a, vector<int>& b, int d = 0) {
  if (l == r) return;
  int m = max_element(begin(a) + l, begin(a) + r) - begin(a);

  b[m] = d;
  resi(l, m, a, b, d+1);
  resi(m+1, r, a, b, d+1);
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    // meh
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++) {
      cin >> a[i];
    }

    resi(0, n, a, b);

    for (int x : b) {
      cout << x << ' ';
    }
    cout << '\n';

  }
}