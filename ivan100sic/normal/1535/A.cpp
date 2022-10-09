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
    int a[4];
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    int b = max(a[0], a[1]);
    int c = max(a[2], a[3]);
    sort(a, a+4);
    cout << (min(b, c) == a[2] ? "YES\n" : "NO\n");
  }
}