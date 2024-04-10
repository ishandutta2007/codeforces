// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

bitset<100> a[15][15];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int x, y, z;
    cin >> x >> y >> z;
    cout << (x * y == z + 1 ? "YES\n" : "NO\n");
  }
}