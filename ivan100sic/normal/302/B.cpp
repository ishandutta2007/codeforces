// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
int c[100005], t[100005];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n >> m;
  for (int i=1; i<=n; i++) {
    cin >> c[i] >> t[i];
  }

  int i = 1, r = c[1] * t[1];

  int last = 0;
  while (m--) {
    int v;
    cin >> v;
    int d = v - last;
    last = v;
    while (1) {
      if (d > r) {
        d -= r;
        i++;
        r = c[i] * t[i];
      } else {
        cout << i << '\n';
        r -= d;
        break;
      }
    }
  }
}