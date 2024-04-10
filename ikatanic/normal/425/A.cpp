#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

int a[202];

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  REP(i, n) scanf("%d", a+i);

  int ans = -1e9;
  REP(r, n) REP(l, r+1) {
    static vector<int> v, w; w.clear(); v.clear();
    REP(i, n)
      if (i < l || i > r) w.push_back(a[i]); else
        v.push_back(a[i]);

    sort(v.begin(), v.end(), greater<int>());
    sort(w.begin(), w.end());
    
    int sum = accumulate(v.begin(), v.end(), 0);

    int rem = k;
    while (rem > 0 && w.size() && v.size() && v.back() < w.back()) {
      sum += w.back() - v.back();
      w.pop_back(), v.pop_back();
      rem--;
    }
    
    ans = max(ans, sum);
  }

  printf("%d\n", ans);
  return 0;
}