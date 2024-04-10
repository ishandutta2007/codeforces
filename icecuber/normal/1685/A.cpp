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
    sort(a.begin(), a.end());
    if (n%2) {
      cout << "NO" << endl;
      continue;
    }
    vector<int> b(n);
    for (int i = 0; i < n/2; i++) {
      b[i*2] = a[i];
      b[i*2+1] = a[i+n/2];
    }
    int ok = 1;
    for (int i = 0; i < n; i++)
      if (b[i] == b[(i+1)%n]) ok = 0;
    if (ok) {
      cout << "YES" << endl;
      for (int v : b) cout << v << ' ';
      cout << endl;
    } else cout << "NO" << endl;
  }
}