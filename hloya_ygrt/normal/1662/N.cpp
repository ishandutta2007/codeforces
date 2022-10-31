#include <bits/stdc++.h>

using namespace std;

bitset<1501> rows[1501];
bitset<1501> cols[1501];

void solve() {
  int n;
  cin >> n;
  std::vector<pair<int, int>> pos;
  pos.reserve(n * n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      x--;
      pos[x] = make_pair(i, j);
    }
  }
  int64_t ans = 0;
  vector<int> cnti(n, n), cntj(n, n);
  int64_t c2 = 0;
  for (int x = 0; x < n * n; x++) {
    auto [i, j] = pos[x];
    cnti[j]--;
    cntj[i]--;
    c2 += cnti[j] * cntj[i];
  }
  int64_t c1 = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      c1 += i * j;
    }
  }
  cout << c1 - (c2 - c1) << "\n";
}


signed main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);
  int t;
  solve();
  return 0;
}