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
    int n, m, z=0;
    cin >> n >> m;
    set<int> a;
    while (n--) {
      int x;
      cin >> x;
      a.insert(x);
    }

    while (m--) {
      int x;
      cin >> x;
      z += a.count(x);
    }

    cout << z << '\n';
  }
}