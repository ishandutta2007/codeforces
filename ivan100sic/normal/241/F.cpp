// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n, m, k;
  cin >> n >> m >> k;
  vector<string> a(n);
  for (int i=0; i<n; i++) cin >> a[i];

  map<char, pair<int, int>> pos;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      pos[a[i][j]] = {i, j};
    }
  }

  int x, y, xt, yt;
  string s;
  cin >> x >> y >> s >> xt >> yt;
  x--, y--;
  xt--, yt--;

  auto ans = [](int x, int y) {
    cout << x+1 << ' ' << y+1 << '\n';
    exit(0);
  };

  auto sgn = [](int x) {
    if (x < 0) return -1;
    else if (x > 0) return 1;
    else return 0;
  };

  auto vl = [&](int x, int y) {
    if (isdigit(a[x][y])) {
      return a[x][y] - '0';
    } else {
      return 1;
    }
  };

  auto mt = [&](int xc, int yc) {
    int d = vl(x, y);
    if (k < d) {
      ans(x, y);
    }
    k -= d;
    x += sgn(xc-x);
    y += sgn(yc-y);
  };

  auto wt = [&](int xc, int yc) {
    while (tie(xc, yc) != tie(x, y)) {
      mt(xc, yc);
    }
  };

  for (char c : s) {
    auto [xc, yc] = pos[c];
    wt(xc, yc);
  }

  wt(xt, yt);
  ans(xt, yt);
}