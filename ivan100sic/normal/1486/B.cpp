// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> x, y;
    for (int i=0; i<n; i++) {
      int a, b;
      cin >> a >> b;
      x.push_back(a);
      y.push_back(b);
    }

    sort(begin(x), end(x));
    sort(begin(y), end(y));

    if (n % 2 == 0) {
      cout << (x[n/2] - x[n/2-1] + 1ll) * (y[n/2] - y[n/2-1] + 1ll) << '\n';
    } else {
      cout << "1\n";
    }
  }
}