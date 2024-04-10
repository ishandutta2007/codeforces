#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<array<int,2>> p[3];
  for (int i = 0; i < n; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    c--;
    p[c].push_back({x,y});
  }
  n /= 3;

  int ans = 0;
  for (int rot = 0; rot < 4; rot++) {
    for (int c = 0; c < 3; c++) {
      for (auto&a : p[c]) {
        a = {a[1], -a[0]};
      }
    }

    vector<int> perm = {0,1,2};
    do {
      vector<int> y0;
      auto &p0 = p[perm[0]], &p1 = p[perm[1]], &p2 = p[perm[2]];
      for (auto [x,y] : p0) y0.push_back(y);
      sort(y0.begin(), y0.end());

      sort(p1.begin(), p1.end());
      sort(p2.begin(), p2.end());

      int pass = 1, fail = n+1;
      while (fail-pass > 1) {
        int m = (pass+fail)/2;

        int ok = 0;
        {
          int my = y0[m-1];
          int takes = 0, lastx = -1;
          for (int i = 0; takes < m && i < n; i++) {
            if (p1[i][1] > my) takes++, lastx = p1[i][0];
          }
          int ok1 = (takes == m);
          int got2s = 0;
          for (int i = 0; ok1 && i < n; i++) {
            got2s += (p2[i][1] > my && p2[i][0] > lastx);
          }
          ok1 &= (got2s >= m);
          ok |= ok1;
        }

        {
          int mx = p1[m-1][0];
          int takes = 0, lastx = -1;
          for (int i = 0; takes < m && i < n; i++) {
            if (p2[i][0] > mx) takes++, lastx = p2[i][0];
          }
          int ok2 = (takes == m);
          int got0s = 0;
          for (int i = 0; ok2 && i < n; i++) {
            got0s += (p0[i][0] > mx && p0[i][0] > lastx);
          }
          ok2 &= (got0s >= m);
          ok |= ok2;
        }

        if (ok) pass = m;
        else fail = m;
      }
      ans = max(ans, pass);

    } while (next_permutation(perm.begin(), perm.end()));
  }
  cout << ans*3 << endl;
}