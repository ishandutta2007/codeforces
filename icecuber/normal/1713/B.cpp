#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int&v : a) cin >> v;
    int down = 0, ok = 1;
    for (int i = 1; i < n; i++) {
      if (a[i-1] > a[i]) down = 1;
      if (a[i-1] < a[i]) {
        if (down) ok = 0;
      }
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}