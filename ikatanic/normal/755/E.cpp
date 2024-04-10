#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);

  if (k == 3 && n >= 4) {
    vector<pair<int, int>> ans = {{0, 1}, {1, 2}, {2, 3}};
    FOR(i, 4, n) ans.push_back({2, i});

    printf("%d\n", (int)ans.size());
    for (auto& p: ans) {
      printf("%d %d\n", p.first+1, p.second+1);
    }
    return 0;
  }

  if (k == 2 && n > 4) {
    vector<pair<int, int>> ans;
    REP(i, n-1) ans.push_back({i, i+1});
    printf("%d\n", (int)ans.size());
    for (auto& p: ans) {
      printf("%d %d\n", p.first+1, p.second+1);
    }
    return 0;
    
  }

  puts("-1");
  return 0;
}