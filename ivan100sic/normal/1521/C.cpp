// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int ask(int t, int i, int j, int x) {
  cout << "? " << t << ' ' << i << ' ' << j << ' ' << x << '\n' << flush;
  int z;
  cin >> z;
  return z;
}

int n;
int a[10005];

void odredi(int i, int j) {
  int hi = ask(1, i, j, n-1);
  if (hi == n-1) {
    hi = max(hi, ask(1, j, i, n-1));
  }
  int lo = ask(2, i, j, 1);
  if (lo == 2) {
    lo = min(lo, ask(2, j, i, 1));
  }

  int q = ask(1, i, j, lo);
  if (q == lo) {
    a[i] = hi;
    a[j] = lo;
  } else {
    a[i] = lo;
    a[j] = hi;
  }
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=1; i+1<=n; i+=2) {
      odredi(i, i+1);
    }
    if (n % 2) {
      odredi(n-1, n);
    }

    cout << '!';
    for (int i=1; i<=n; i++) {
      cout << ' ' << a[i];
    }
    cout << '\n' << flush;
  }
}