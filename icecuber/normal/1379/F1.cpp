#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w, q;
  cin >> h >> w >> q;
  vector<pair<int,int>> p(q);
  for (auto&[r,c] : p) {
    cin >> r >> c;
    r--, c--;
  }
  int pass = 0, fail = q+1;
  while (fail-pass > 1) {
    int mid = (pass+fail)/2;
    vector<int> mi(w, h);
    for (int i = 0; i < mid; i++) {
      auto [r, c] = p[i];
      int y = r/2, x = c/2;
      if (r%2 == 0) {
	mi[x] = min(mi[x], y);
      }
    }
    for (int i = 0; i+1 < w; i++) {
      mi[i+1] = min(mi[i+1], mi[i]);
    }
    int ok = 1;
    for (int i = 0; i < mid; i++) {
      auto [r, c] = p[i];
      int y = r/2, x = c/2;
      if (r%2) {
	if (y >= mi[x]) ok = 0;
      }
    }
    if (ok) pass = mid;
    else fail = mid;
  }
  for (int i = 1; i <= q; i++) {
    cout << (i <= pass ? "YES" : "NO") << endl;
  }
}