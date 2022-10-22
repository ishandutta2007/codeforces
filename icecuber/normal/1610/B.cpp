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
    for (int i = 0; n-1-i > i; i++) {
      if (a[i] != a[n-1-i]) {
        for (int x : {a[i], a[n-1-i]}) {
          vector<int> b;
          for (int v : a) if (v != x) b.push_back(v);
          auto r = b;
          reverse(r.begin(), r.end());
          if (r == b) {
            cout << "YES" << endl;
            goto next;
          }
        }
        cout << "NO" << endl;
        goto next;
      }
    }
    cout << "YES" << endl;
    next:;
  }
}