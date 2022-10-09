// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    set<int> s;
    auto it = s.end();
    string ans = "YES\n";
    for (int i=0; i<n; i++) {
      int x;
      cin >> x;
      if (s.empty()) {
        s.insert(x);
        it = s.find(x);
      } else {
        bool ok = false;
        auto ti = s.insert(x).first;
        if (ti != s.begin() && prev(ti) == it) {
          ok = true;
        }

        if (next(ti) == it) {
          ok = true;
        }

        if (ti == it) {
          ok = true;
        }

        it = ti;
        if (!ok) {
          ans = "NO\n";
        }
      }
    }

    cout << ans;
  }
}