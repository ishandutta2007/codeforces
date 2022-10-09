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
    vector<int> a(n);
    for (int& x : a) cin >> x;

    const int H = 1'000'000'006;
    cout << n-1 << '\n';
    for (int i=n-1; i>0; i--) {
      int x = min(a[i-1], a[i]);
      int y = H+i;
      cout << i << ' ' << i+1 << ' ' << x << ' ' << y << '\n';
      a[i-1] = x;
      a[i] = y;
    }
  }
}