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
    vector<int> a(n), b(n);
    for (int&v : a) cin >> v;
    for (int&v : b) cin >> v;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ok = 1;
    for (int i = 0; i < n; i++) {
      if (b[i] != a[i] && b[i] != a[i]+1) ok = 0;
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}