// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int ask(int l, int r) {
  cout << "? " << l << ' ' << r << '\n' << flush;
  int x;
  cin >> x;
  return x;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n;
  cin >> n;

  int s = ask(1, n);

  int l = 1, r = n-1, o = -1;
  while (l <= r) {
    int m = (l+r) / 2;

    int w = m;
    int u = s, v = s;
    int d = min(n-v, w);
    v += d;
    w -= d;
    u -= w;

    int j = ask(u, v);
    if (j == s) {
      o = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  if (s+o <= n) {
    cout << "! " << s+o << '\n';
  } else {
    cout << "! " << n-o << '\n';
  }

  cout << flush;

}