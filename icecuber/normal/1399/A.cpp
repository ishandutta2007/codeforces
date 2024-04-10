#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int mi = 1e9, ma = -1e9;
    set<int> diff;
    for (int i = 0; i < n; i++) {
      int v;
      cin >> v;
      diff.insert(v);
      mi = min(mi, v);
      ma = max(ma, v);
    }
    cout << (ma-mi+1 == diff.size() ? "YES" : "NO") << endl;
  }
}