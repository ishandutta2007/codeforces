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
    int n, z=0;
    cin >> n;
    map<int, int> a;
    while (n--) {
      int x;
      cin >> x;
      z = max(z, ++a[x]);
    }
    cout << z << '\n';
  }
}