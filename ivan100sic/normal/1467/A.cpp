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
    cout << 9;

    for (int i=2; i<=n; i++) {
      cout << (6+i) % 10;
    }
    cout << '\n';
  }
}