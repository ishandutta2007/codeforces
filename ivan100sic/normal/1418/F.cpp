// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll n, m, l, r;
basic_string<int> divs[200005];

/*
	x*a = b*c

	l <= x*a <= r
	a <= m

	lo = ceil(l/x)
	hi = min(floor(r/x), m)

	let g | x,b

	then b = x+yg, y > 0, y <= floor((n-x)/g)
	then b/g | a, so a = (b/g)z = (x/g+y)z


*/

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n >> m >> l >> r;

  for (int i=1; i<=n; i++) {
    for (int j=i; j<=n; j+=i) {
      divs[j] += i;
    }
  }


  for (ll x=1; x<=n; x++) {
    ll lo = (l+x-1) / x;
    ll hi = min(r/x, m);
    if (lo > hi) {
      cout << "-1\n";
      continue;
    }

    bool ok = false;

    for (ll g : divs[x]) {
			if (ok) break;
      if (g*g <= x) {
        // a = (x/g+y)z
        for (ll z=1; z<=hi/(x/g+1); z++) {
          ll lo2 = (lo+z-1) / z;
          ll hi2 = hi / z;

					lo2 -= x/g;
					hi2 -= x/g;

					lo2 = max(lo2, 1ll);
					hi2 = min(hi2, (n-x) / g);

					if (lo2 <= hi2) {
						// eto ga y
						ll y = lo2;
						ll b = x+y*g;
						ll a = (x/g+y)*z;
						ll c = x*a/b;
						cout << x << ' ' << a << ' ' << b << ' ' << c << '\n';
						ok = 1;
						break;
					}
        }
      } else {
				for (ll b=x+g; b<=n; b+=g) {
					ll a = hi/(b/g)*(b/g);
					if (a >= lo) {
						ll c = x*a/b;
						cout << x << ' ' << a << ' ' << b << ' ' << c << '\n';
						ok = 1;
						break;
					}
				}
			}
    }

		if (!ok) {
			cout << "-1\n";
		}
  }
}