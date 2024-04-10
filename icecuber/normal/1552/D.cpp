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
    const int nax = 1e6+10;
    vector<int> has(nax);
    has[0] = 1;
    int ok = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      a = abs(a);
      if (has[a]) ok = 1;
      auto cp = has;
      for (int j = 0; j < nax; j++) {
        if (cp[j]) has[abs(j-a)] = has[abs(j+a)] = 1;
      }
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}