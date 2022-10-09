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
    int s = 0;
    cin >> n;

    for (int i=0; i<n; i++) {
      int r;
      cin >> r;
      s += r % 2;
    }

    cout << s << '\n';
  }
}