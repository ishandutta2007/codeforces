// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll n, h;
ll x[200005], y[200005];

ld sq(ld x) {
  return x*x;
}

ld det(ld ax, ld ay, ld bx, ld by, ld cx, ld cy) {
  return ax*by + bx*cy + cx*ay - ay*bx - by*cx - cy*ax;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n >> h;
  for (ll i=0; i<n; i++) {
    cin >> x[i] >> y[i];
  }

  ld sol = 0;
  int horizon = n-1;

  ld ex = x[n-1], ey = y[n-1] + h;

  for (int i=n-2; i>=0; i--) {
    // i -- i+1
    ld diii = det(ex, ey, x[i+1], y[i+1], x[i], y[i]);
    ld dhi = det(ex, ey, x[horizon], y[horizon], x[i], y[i]);
    ld dhii = det(ex, ey, x[horizon], y[horizon], x[i+1], y[i+1]);
    ld len = sqrt(sq(x[i] - x[i+1]) + sq(y[i] - y[i+1]));

    if (diii > 0) {
      // mnogo lose
    } else if (diii == 0) {
      // ajde da resimo odma ovaj degenericni slucaj
      if (dhi <= 0) {
        sol += len;
      }
    } else {
      if (dhi <= 0 && dhii <= 0) {
        sol += len;
      } else if (dhi > 0 && dhii > 0) {
        // nista se ne vidi
      } else {
        ld lo = 0, hi = 1;
        int steps = 50;
        while (steps--) {
          ld mid = (lo + hi) / 2;
          ld xx = x[i] * (1 - mid) + x[i+1] * mid;
          ld yy = y[i] * (1 - mid) + y[i+1] * mid;

          ld dd = det(ex, ey, x[horizon], y[horizon], xx, yy);
          if (dd <= 0) {
            lo = mid;
          } else {
            hi = mid;
          }
        }

        sol += len * lo;
      }
    }
    if (det(ex, ey, x[horizon], y[horizon], x[i], y[i]) < 0) {
      horizon = i;
    }
  }

  cout << setprecision(20) << fixed << sol << '\n';
}