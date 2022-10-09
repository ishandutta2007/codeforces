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
    int n, f=0;
    cin >> n;
    for (int x=0; x<=n; x+=2020) {
      if ((n-x) % 2021 == 0) {
        f = 1;
        break;
      }
    }
    cout << "NO\n\0YES\n"+4*f;
  }
}