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
    set<int> a;
    for (int i = 0; i < n; i++) {
      int v;
      cin >> v;
      a.insert(v);
    }
    if (!a.count(1)) {
      cout << "YES" << endl;
      continue;
    }
    int p = -2, ok = 1;
    for (int v : a) {
      if (v == p+1) ok = 0;
      p = v;
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}