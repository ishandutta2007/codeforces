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
    vector<int> a(n),b(n);
    for (int&v : a) cin >> v;
    for (int&v : b) cin >> v;
    int has[3] = {};
    int ok = 1;
    for (int i = 0; i < n; i++) {
      if (b[i] > a[i] && !has[2]) ok = 0;
      if (b[i] < a[i] && !has[0]) ok = 0;
      has[a[i]+1] = 1;
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}