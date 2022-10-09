// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

bool moze(ll a, ll b, ll c, ll d, ll x, ll y) {
  if (!a && !c) return false;
  if (!b && !d) return false;

  // prvi deo, (0, y)?
  ll p = -c;
  ll q = a;
  ll g = gcd(abs(p), abs(q));
  p /= g;
  q /= g;

  ll yy = p*b + q*d;
  if (yy == 0) return false;
  if (y % yy) return false;

  if (x % g) return false;
  return true;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  ll n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;

  if (n != abs(a*d-b*c)) {
    cout << "NO\n";
    return 0;
  }

  for (ll x=1; x<=n; x++) {
    if (n % x) continue;
    ll y = n / x;

    // ako napravis (0, y) i (x, z) za neko z, onda moze
    // moze i ako napravis (x, 0) i (z, y) za neko z

    if (moze(a, b, c, d, x, y) || moze(b, a, d, c, y, x)) {
      cout << "YES\n";
      for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
          cout << i << ' ' << j << '\n';
        }
      }
      return 0;
    }
  }

  cout << "NO\n";
}