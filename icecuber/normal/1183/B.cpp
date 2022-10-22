#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int mi = 1, ma = 1e9;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      mi = max(mi, a-k);
      ma = min(ma, a+k);
    }
    cout << (ma >= mi ? ma : -1) << endl;
  }
}