#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void fail() {
  cout << -1 << endl;
  exit(0);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<array<int,2>> a(n), pos(n*2);
  for (int i = 0; i < n; i++) {
    for (int k : {0,1}) {
      cin >> a[i][k];
      a[i][k]--;
      pos[a[i][k]] = {i,k};
    }
  }

  vector<int> done(n*2);
  int dones = 0;

  int ans = 0;
  int l = 0, r = n*2-1;
  int x0 = 0, x1 = n*2-1, y0 = n*2-1, y1 = 0;

  while (dones < n) {
    int flip = 0, tot = 0;

    auto putl = [&]() {
      assert(!done[l]);

      auto [i,k] = pos[l];
      tot++;
      if (k) flip++;

      int x = l, y = a[i][!k];
      //cout << "left " << x << ' ' << y << endl;
      assert(x >= x0);
      if (y > y0 || y < y1) fail();
      x0 = x;
      y0 = y;
      done[x] = done[y] = 1;
      dones++;
      while (l <= r && done[l]) l++;
      while (l <= r && done[r]) r--;
    };

    auto putr = [&]() {
      assert(!done[r]);

      auto [i,k] = pos[r];
      tot++;
      if (k) flip++;

      int x = r, y = a[i][!k];
      //cout << "right " << x << ' ' << y << endl;
      assert(r <= x1);
      if (y > y0 || y < y1) fail();
      x1 = x;
      y1 = y;
      done[x] = done[y] = 1;
      dones++;
      while (l <= r && done[l]) l++;
      while (l <= r && done[r]) r--;
    };


    putl();
    while ((l < y1 || r > y0) && dones < n) {
      //cout << x0 << ' ' << y0 << " , " << x1 << ' ' << y1 << " , " << l << ' ' << r << endl;
      //assert(x0 <= y1 && y0 <= x1);
      if (l < y1) {
        putl();
      } else {
        assert(r > y0);
        putr();
      }
    }
    assert(dones*2 + r-l+1 == n*2);
    ans += min(flip, tot-flip);
  }
  cout << ans << endl;
}