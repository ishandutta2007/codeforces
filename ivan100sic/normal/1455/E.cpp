// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll x[4], y[4], sol;

void probaj(ll p, ll q, ll w) {
  pair<ll, ll> a[4] = {{p, q}, {p, q+w}, {p+w, q}, {p+w, q+w}};
  sort(a, a+4);

  do {
    ll s = 0;
    for (int i=0; i<4; i++) {
      s += abs(a[i].first - x[i]) + abs(a[i].second - y[i]);
    }
    sol = min(sol, s);
  } while (next_permutation(a, a+4));
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    for (int i=0; i<4; i++) {
      cin >> x[i] >> y[i];
    }

    sol = 1e18;

    vector<ll> ww;
    for (int i=0; i<4; i++) {
      for (int j=i+1; j<4; j++) {
        ww.push_back(abs(x[i] - x[j]));
        ww.push_back(abs(y[i] - y[j]));
      }
    }

    sort(begin(ww), end(ww));
    ww.erase(unique(begin(ww), end(ww)), end(ww));

    for (ll w : ww) {
      for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
          probaj(x[i], y[j], w);
          probaj(x[i]-w, y[j], w);
          probaj(x[i], y[j]-w, w);
          probaj(x[i]-w, y[j]-w, w);
        }
      }
    }

    cout << sol << '\n';
  }
}