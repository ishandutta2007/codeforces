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

const llint inf = 1e18;

vector<int> v[5];
vector<int> pos[5];
int n, k;
llint b, c;
  
llint getCost(llint x, llint t) {
  assert(x <= t);
  return (t-x)/5*b + (t-x)%5*c;
}

llint solve(vector<int>& pos) {
  sort(pos.begin(), pos.end());
  pos.erase(unique(pos.begin(), pos.end()), pos.end());

  static int l[5], r[5];
  REP(i, 5) l[i] = r[i] = 0;

  llint ans = inf;

  int cnt = 0;
  int last = pos[0];
  llint cost = 0;
  for (int x: pos) {
    cost += cnt * b * (x - last) / 5;
    last = x;

    REP(i, 5) {
      while (r[i] < (int)v[i].size() && v[i][r[i]] <= x) {
        cnt++;
        cost += getCost(v[i][r[i]++], x);
      }
    }

    while (cnt > k) {
      llint maks = -inf;
      int id = -1;
      REP(i, 5) {
        if (l[i] < r[i]) {
          llint maxc = getCost(v[i][l[i]], x);
          if (maxc > maks) maks = maxc, id = i;
        }
      }
      assert(id != -1);
      cost -= getCost(v[id][l[id]++], x);
      cnt--;
    }

    if (cnt == k) ans = min(ans, cost);
  }
  return ans;
}

int mod5(int x) {
  x %= 5;
  if (x < 0) x += 5;
  return x;
}

int main(void) {
  scanf("%d %d %lld %lld", &n, &k, &b, &c);
  b = min(b, 5 * c);
  vector<int> t(n);
  REP(i, n) scanf("%d", &t[i]);
  sort(t.begin(), t.end());
  for (int x: t) v[mod5(x)].push_back(x);
  REP(i, n) REP(j, 5) pos[mod5(t[i]+j)].push_back(t[i] + j);

  llint ans = inf;
  REP(j, 5) ans = min(ans, solve(pos[j]));
  printf("%lld\n", ans);
  return 0;
}