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
    int n, ok = 1;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
      int x;
      cin >> x;
      if (x < 0) {
        ok = 0;
      }
    }

    if (!ok) {
      cout << "no\n";
      continue;
    }

    cout << "Yes\n101\n";
    for (int i=0; i<=100; i++) {
      cout << i << " \n"[i == 100];
    }
  }
}