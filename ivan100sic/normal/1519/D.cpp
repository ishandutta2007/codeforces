// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
ll a[5005], b[5005];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }
  for (int i=0; i<n; i++) {
    cin >> b[i];
  }

  ll p = inner_product(a, a+n, b, 0ll);
  ll sol = p;

  auto go = [&](int l, int r, ll p) {
    while (l >= 0 && r < n) {
      p -= a[l] * b[l] + a[r] * b[r];
      p += a[r] * b[l] + a[l] * b[r];
      sol = max(sol, p);
      l--;
      r++;
    }
  };

  for (int i=0; i<n; i++) {
    if (i + 1 < n) go(i, i+1, p);
    go(i, i, p);
  }

  cout << sol << '\n';
}