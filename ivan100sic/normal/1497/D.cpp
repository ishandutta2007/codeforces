// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const ll inf = 1e18;

void mx(ll& x, ll y) {
  x = max(x, y);
}

int n;
int tg[5005], s[5005];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=1; i<=n; i++) {
      cin >> tg[i];
    }

    for (int i=1; i<=n; i++) {
      cin >> s[i];
    }

    vector<ll> we(2, -inf);
    we[1] = 0;

    for (int i=2; i<=n; i++) {
      vector<ll> up(i+1, -inf), dn(i+1, -inf);
      for (int j=1; j<i; j++) {
        if (tg[j] != tg[i]) {
          mx(up[j], we[j] + abs(s[j] - s[i]));
        }
      }
      up[i] = 0;
      ll sofar = 0;
      for (int j=i-1; j>0; j--) {
        if (tg[j] != tg[i]) {
          mx(dn[j], sofar + abs(s[j] - s[i]));
          mx(sofar, up[j]);
        }
      }

      ll nwe = -inf;
      for (int j=1; j<=i; j++) {
        mx(nwe, up[j]);
      }
      we.push_back(nwe);

      for (int j=1; j<i; j++) {
        mx(we[j], dn[j]);
      }
    }

    cout << *max_element(begin(we), end(we)) << '\n';
  }
}