#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <set>
#include <queue>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 202000;

llint ans[MAX];
int d[MAX];

int main(void) {
  queue<int> Q;

  int n, b;
  scanf("%d %d", &n, &b);

  llint time_done = 0;
  int cur = -1;
  REP(i, n) {
    int t;
    scanf("%d %d", &t, d+i);
    ans[i] = -1;
    
    while (cur != -1 && time_done <= t) {
      ans[cur] = time_done;
      if (Q.empty()) {
        cur = -1;
      } else {
        cur = Q.front(); Q.pop();
        time_done += d[cur];
      }
    }

    if (cur == -1) {
      cur = i;
      time_done = t + d[i];
    } else {
      if ((int)Q.size() < b) Q.push(i);
    }
  }
  
  while (cur != -1) {
    ans[cur] = time_done;
    if (Q.empty()) {
      cur = -1;
    } else {
      cur = Q.front(); Q.pop();
      time_done += d[cur];
    }
  }
  
  REP(i, n) printf("%lld ", ans[i]);
  printf("\n");
  return 0;
}