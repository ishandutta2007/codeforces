#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

map<int, int> rem;

int main(void) {
  int n;
  scanf("%d", &n);
  vector<int> v;
  REP(i, n) REP(j, n) {
    int x;
    scanf("%d", &x);
    v.push_back(x);
  }

  sort(v.rbegin(), v.rend());

  vector<int> ans;
  for (int x: v) {
    if (rem[x] > 0) {
      rem[x]--;
      continue;
    }

    for (int y: ans) rem[__gcd(y, x)] += 2;
    ans.push_back(x);
  }
  assert((int)ans.size() == n);
  for (int x: ans) printf("%d ", x);
  printf("\n");
  return 0;
}