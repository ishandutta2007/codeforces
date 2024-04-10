#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>
#include <map>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int ans[100100];

int n, a, b;
set<int> bio, cur, nums;
map<int, int> id;

void dfs(int x) {
  if (!nums.count(x) || bio.count(x)) return;
  cur.insert(x);
  bio.insert(x);
  dfs(a - x);
  dfs(b - x);
}

int main(void) {
  scanf("%d %d %d", &n, &a, &b);
  REP(i, n) {
    int x;
    scanf("%d", &x);
    nums.insert(x);
    id[x] = i;
  }

  for (int x: nums)
    if (!bio.count(x)) {
      cur.clear();
      dfs(x);
      
      bool cana = true;
      bool canb = true;
      for (int y: cur) {
        if (!cur.count(a - y)) cana = false;
        if (!cur.count(b - y)) canb = false;
      }

      if (!cana && !canb) {
        puts("NO");
        return 0;
      }

      for (int y: cur)
        ans[id[y]] = canb;
    }

  puts("YES");
  REP(i, n)
    printf("%d%c", ans[i], i < n-1 ? ' ' : '\n');
  return 0;
}