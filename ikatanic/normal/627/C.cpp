#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 200200;

pair<int, int> a[MAX];

int main(void) {
  int d, n, c;
  scanf("%d %d %d", &d, &c, &n);

  REP(i, n) scanf("%d %d", &a[i].first, &a[i].second);
  a[n++] = {0, 0};
  a[n++] = {d, 0};
  sort(a, a + n);

  llint ans = 0;
  multiset<pair<int, int>> S;
  
  int j = 0;
  REP(i, n-1) {
    S.insert({a[i].second, a[i].first});
    
    int pos = a[i].first;
    int next = a[i+1].first;
    while (pos < next) {
      while (j <= i && a[j].first + c <= pos) {
        S.erase({a[j].second, a[j].first});
        j++;
      }

      if (S.empty()) {
        puts("-1");
        return 0;
      }

      int take = min(next - pos, c - (pos - S.begin()->second));
      assert(take > 0);
      ans += llint(take) * S.begin()->first;
      pos += take;
    }
  }

  printf("%lld\n", ans);
  return 0;
}