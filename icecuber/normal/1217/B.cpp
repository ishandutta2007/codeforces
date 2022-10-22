#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    int best = 0, last = 0;
    for (int i = 0; i < n; i++) {
      int d, h;
      cin >> d >> h;
      if (d-h > best) best = d-h;
      if (d > last) last = d;
    }

    if (last >= x) {
      cout << 1 << endl;
    } else if (best <= 0) {
      cout << -1 << endl;
    } else {
      cout << (x-last+best-1)/best+1 << endl;
    }
  }
}