// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n, k;
  cin >> n >> k;
  if (n < 3*k || k == 1) {
    cout << "-1\n";
    return 0;
  }

  for (int i=0; i<2*k; i++) {
    cout << 1 + i/2 << ' ';
  }

  for (int i=2*k; i<n; i++) {
    cout << min(k, i-2*k+1) << ' ';
  }

  cout << '\n';

}