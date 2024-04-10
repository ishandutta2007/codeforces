#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string a, b, c;
    cin >> a >> b >> c;
    int ok = 1;
    for (int i = 0; i < a.size(); i++) {
      if (!(a[i] == c[i] || b[i] == c[i])) ok = 0;
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}