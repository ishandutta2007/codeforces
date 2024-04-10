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
    for (int a = 0; a*3 <= n; a++) {
      for (int b = 0; a*3+b*5 <= n; b++) {
        int c = n-a*3-b*5;
        if (c%7) continue;
        cout << a << ' ' << b << ' ' << c/7 << endl;
        goto found;
      }
    }
    cout << -1 << endl;
    continue;
  found:
    ;
  }
}