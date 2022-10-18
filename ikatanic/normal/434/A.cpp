#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

int a[100100];
vector<int> v[100100];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);

  llint total = 0;
  REP(i, m) {
    scanf("%d", a+i); --a[i];
    if (i > 0) total += abs(a[i]-a[i-1]);
  }

  REP(i, m) {
    if (i > 0 && a[i-1] != a[i]) v[a[i]].push_back(a[i-1]);
    if (i+1 < m && a[i+1] != a[i]) v[a[i]].push_back(a[i+1]);
  }

  llint best = total;
  REP(i, n) 
    if (v[i].size()) {
      sort(v[i].begin(), v[i].end());

      llint suml = 0, sumr = 0, cntl = 0, cntr = 0;
      llint cur = 0;
      for (int y: v[i]) {
        cur += abs(y-i);
        sumr += y, cntr++;
      }
      llint rem = total - cur;

      for (int y: v[i]) {
        cur = min(cur, (cntl-cntr)*y - suml + sumr);
        suml += y, cntl++;
        sumr -= y, cntr--;
      }
      best = min(best, rem + cur);
    }

  cout << best << endl;
  return 0;
}