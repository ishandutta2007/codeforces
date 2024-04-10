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

struct Interval {
  llint a, b;
  int i;
  friend bool operator < (const Interval &a, const Interval &b) {
    return a.b < b.b;
  }
};

llint l[MAX], r[MAX];
int ans[MAX];
set<pair<llint, int>> S;

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) scanf("%lld %lld", &l[i], &r[i]);

  vector<Interval> v;
  REP(i, n-1) v.push_back({l[i+1]-r[i], r[i+1]-l[i], i});
  sort(v.begin(), v.end());

  REP(i, m) {
    llint x;
    scanf("%lld", &x);
    S.insert({x, i});
  }

  for (auto& p: v) {
    auto it = S.lower_bound({p.a, -1});
    if (it == S.end() || it->first > p.b) {
      puts("No");
      return 0;
    }
    assert(it->first >= p.a);
    ans[p.i] = it->second;
    S.erase(it);
  }

  puts("Yes");
  REP(i, n-1) printf("%d ", ans[i]+1);
  printf("\n");
  return 0;
}