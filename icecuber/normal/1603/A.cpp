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
    int ok = 1;
    for (int i = 0; i < n; i++) {
      int found = 0;
      for (int j = 2; j <= i+2; j++) {
        if (a[i]%j) {
          found = 1;
          break;
        }
      }
      ok &= found;
      if (!ok) break;
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}