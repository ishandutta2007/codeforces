// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

bool probaj(vector<int> a, int x, bool pr = false) {
  multiset<int> s(begin(a), end(a));
  while (s.size()) {
    int y = *prev(s.end());
    int z = x - y;
    auto it = s.lower_bound(z);
    if (it == s.end()) return false;
    if (it == prev(s.end())) return false;
    if (*it != z) return false;
    if (pr) {
      cout << z << ' ' << y << '\n';
    }
    s.erase(it);
    s.erase(prev(s.end()));
    x = y;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(2*n);
    for (int& x : a) cin >> x;

    sort(begin(a), end(a));

    int f = 0;
    for (int i=0; i<2*n-1; i++) {
      int x = a[2*n-1] + a[i];
      if (probaj(a, x)) {
        cout << "YES\n";
        cout << x << '\n';
        probaj(a, x, 1);
        f = 1;
        break;
      }
    }

    if (!f) {
      cout << "NO\n";
    }
  }
}