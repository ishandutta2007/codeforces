#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a;
    cin >> a;
    int found = 0;
    for (int n = 3; n < 1000; n++) {
      if (a*n%180) continue;
      int k = a*n/180;
      if (k > n-2) continue;
      cout << n << endl;
      found = 1;
      break;
    }
    if (!found) cout << -1 << endl;
  }
}