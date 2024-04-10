#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    set<int> s;
    for (int i = 0; i < n; i++) {
      int v;
      cin >> v;
      s.insert(v);
    }
    int ok = 0;
    for (int i : s) if (s.count(i+k)) ok = 1;
    cout << (ok ? "YES" : "NO") << endl;
  }
}