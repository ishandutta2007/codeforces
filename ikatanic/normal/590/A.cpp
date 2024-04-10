#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 500500;

int main(void) {
  int n;
  scanf("%d", &n);

  vector<pair<int, int>> v;
  int cur = 0, cnt = 0;
  REP(i, n) {
    int x;
    scanf("%d", &x);
    if (i == 0) cur = x, cnt = 2; else {
      if (cur == x) cnt++; else {
        v.push_back({cur, cnt});
        cur = x, cnt = 1;
      }
    }
  }

  cnt++;
  v.push_back({cur, cnt});

  static int ans[MAX];
  int m = 0;
  int i = 0;
  int ans_cnt = 0;
  while (i < (int)v.size()) {
    assert(v[i].second > 1);    
    REP(k, v[i].second) ans[m++] = v[i].first;
    if (i == (int)v.size()-1) break;

    int j = i + 1;
    while (v[j].second == 1) j++;

    if (v[i].first == v[j].first) {
      int len = j - i - 1;
      assert(len % 2 == 1);
      ans_cnt = max(ans_cnt, (len + 1) / 2);
      REP(k, len) ans[m++] = v[i].first;
    } else {
      int len = j - i - 1;
      assert(len % 2 == 0);
      ans_cnt = max(ans_cnt, len / 2);
      REP(k, len/2) ans[m++] = v[i].first;
      REP(k, len/2) ans[m++] = v[j].first;
    }

    i = j;
  }

  printf("%d\n", ans_cnt);
  assert(m == n + 2);
  REP(i, n) printf("%d ", ans[i+1]);
  printf("\n");
  return 0;
}