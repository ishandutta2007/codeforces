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
typedef pair<int, int> par;

const int MAX = 100100;
const int off = 1<<18;

set<par> S[2*off];
int dad[MAX];

par find(int i, int lo, int hi, int x, int y) {
  if (hi <= x) return {-1, -1};
  auto it = S[i].lower_bound({y, -1});
  if (it == S[i].end()) return {-1, -1};
  if (i >= off) {
    auto ans = *it;
    S[i].erase(it);
    return ans;
  }

  auto l = find(i*2, lo, (lo+hi)/2, x, y);
  if (l.second != -1) {
    S[i].erase(l);
    return l;
  }
  auto r = find(i*2+1, (lo+hi)/2, hi, x, y);
  if (r.second != -1) S[i].erase(r);
  return r;
}

int main(void) {
  static int a[MAX], b[MAX], c[MAX], d[MAX];

  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);

  vector<int> v = {0};
  REP(i, n) {
    v.push_back(a[i]);
    v.push_back(c[i]);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  
  REP(i, n) {
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    c[i] = lower_bound(v.begin(), v.end(), c[i]) - v.begin();
  }

  REP(i, n-1) {
    for (int x = off + c[i]; x; x /= 2)
      S[x].insert({d[i], i});
  }

  queue<int> Q;
  dad[n-1] = -1;
  Q.push(n-1);

  while (!Q.empty()) {
    int i = Q.front(); Q.pop();

    if (a[i] == 0 && b[i] == 0) {
      vector<int> ans;
      while (i != -1) {
        ans.push_back(i);
        i = dad[i];
      }

      printf("%d\n", (int)ans.size());
      for (int x: ans) printf("%d ", x+1);
      printf("\n");
      return 0;
    }

    while (true) {
      int j = find(1, 0, off, a[i], b[i]).second;
      if (j == -1) break;
      dad[j] = i;
      Q.push(j);
    }
  }

  puts("-1");
  return 0;
}