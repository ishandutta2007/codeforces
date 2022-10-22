#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    set<array<int,2>> swaps;
    int ok = 1;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++)
        cin >> a[i][j];
      vector<int> sorted = a[i];
      sort(sorted.begin(), sorted.end());
      vector<int> diffs;
      for (int j = 0; j < w; j++) {
        if (sorted[j] != a[i][j]) diffs.push_back(j);
      }
      if (diffs.size() == 0) continue;
      if (diffs.size() == 2) {
        swaps.insert({diffs[0],diffs[1]});
      } else {
        ok = 0;
      }
    }
    if (ok && swaps.empty()) {
      cout << "1 1" << endl;
      continue;
    }
    if (swaps.size() == 1) {
      auto [u,v] = *swaps.begin();
      for (int i = 0; i < h; i++) {
        swap(a[i][u], a[i][v]);
        for (int j = 1; j < w; j++)
          if (a[i][j] < a[i][j-1]) ok = 0;
      }
    } else ok = 0;
    if (!ok) {
      cout << -1 << endl;
    } else {
      auto [u,v] = *swaps.begin();
      cout << u+1 << ' ' << v+1 << endl;
    }
  }
}