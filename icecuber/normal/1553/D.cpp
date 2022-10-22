#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int i = 0, ok = 1;
    for (char c : b) {
      while (i < (int)a.size() && a[i] != c) i += 2;
      if (i >= (int)a.size()) {
        ok = 0;
        break;
      }
      i++;
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}