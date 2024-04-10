#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const llint inf = 1e18;

int main(void) {
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  llint minx = inf, maxx = -inf, miny = inf, maxy = -inf;

  vector<pair<llint, llint>> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i].first >> A[i].second;
    minx = min(minx, A[i].first);
    miny = min(miny, A[i].second);
    maxx = max(maxx, A[i].first);
    maxy = max(maxy, A[i].second);
  }

  llint ans4 = 2 * (maxx - minx) + 2 * (maxy - miny);

  llint ans3 = 0;

  for (int s = 0; s < (1 << 6); ++s) {
    vector<int> cntx(3, 0), cnty(3, 0);
    for (int i = 0; i < 3; ++i) {
      if (s & (1 << i)) {
        cntx[i]++;
        cntx[(i + 1) % 3]--;
      } else {
        cntx[i]--;
        cntx[(i + 1) % 3]++;
      }
      if (s & (1 << (3 + i))) {
        cnty[i]++;
        cnty[(i + 1) % 3]--;
      } else {
        cnty[i]--;
        cnty[(i + 1) % 3]++;
      }
    }

    llint perim = 0;
    for (int i = 0; i < 3; ++i) {
      llint best = -1e18;
      for (auto& p : A) {
        best = max(best, p.first * cntx[i] + p.second * cnty[i]);
      }
      perim += best;
    }

    ans3 = max(ans3, perim);
  }

  cout << ans3;
  for (int i = 4; i <= N; ++i) {
    cout << " " << ans4;
  }
  cout << "\n";
  return 0;
}