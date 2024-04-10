#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> d(m), h(m);
  for (int i = 0; i < m; ++i) {
    cin >> d[i] >> h[i];
  }
  int res = max(h[0] + d[0] - 1, n - d.back() + h.back());
  for (int i = 1; i < m; ++i) {
    int dh = abs(h[i] - h[i - 1]);
    int dd = d[i] - d[i - 1];
    if (dh > dd) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
    dd -= dh;
    res = max(res, max(h[i], h[i - 1]) + dd / 2);
  }
  cout << res << endl;
  return 0;
}