#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;
typedef pair<int, llint> par;

vector<int> v[2];

int countLess(vector<int> &v, int x) {
  return (lower_bound(v.begin(), v.end(), x) - v.begin());
}

int countEqual(vector<int> &v, int x) {
  return (upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x));
}

int countGreater(vector<int> &v, int x) {
  return (v.end() - upper_bound(v.begin(), v.end(), x));
}

void update(par &ans, par c) {
  if (c.second == 0) return;
  if (c.first > ans.first) ans.first = c.first, ans.second = 0;
  if (c.first == ans.first) ans.second += c.second;
}

par solve(int n, vector<int> &v, vector<int> &z) {
  int cnt = v.size();
  int cntZ = z.size();

  par ans(0, 0);
  if (cnt >= 3) { // 3 jedinice
    int miniCnt = countEqual(v, v[0]);
    int maksCnt = countEqual(v, v.back());
    if (v[0] == v.back()) update(ans, {0, llint(miniCnt)*(miniCnt-1)*(miniCnt-2)/2/3}); else {
      llint ways = llint(cnt-miniCnt-maksCnt)*miniCnt*maksCnt;
      ways += llint(miniCnt)*(miniCnt-1)/2*maksCnt;
      ways += llint(maksCnt)*(maksCnt-1)/2*miniCnt;
      update(ans, {v.back()-v[0], ways});
    }
  }
  
  REP(i, cnt) {
    // a <= b <= c
    int c = lower_bound(z.begin(), z.end(), v[i]) - z.begin();
    if (c >= 0 && c < cntZ) update(ans, {n - z[c] + v[i], llint(i)*countEqual(z, z[c])});
    // c <= a <= b
    c = upper_bound(z.begin(), z.end(), v[i]) - z.begin() - 1;
    if (c >= 0 && c < cntZ) update(ans, {n - v[i] + z[c], llint(cnt-i-1)*countEqual(z, z[c])});
  }

  REP(i, cntZ) {
    int l = countLess(v, z[i]);
    int e = countEqual(v, z[i]);
    int g = countGreater(v, z[i]);
    // a < c < b
    update(ans, {n, llint(l)*g});
    // oduzmi a == b == c 
    if (ans.first == n) ans.second -= llint(e)*(e-1)/2;
  }
  return ans;
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, m) {
    int s, f;
    scanf("%d %d", &s, &f);
    v[s].push_back(f);
  }

  sort(v[0].begin(), v[0].end());
  sort(v[1].begin(), v[1].end());

  par p0 = solve(n, v[0], v[1]);
  par p1 = solve(n, v[1], v[0]);
  update(p0, p1);
  cout << p0.second << endl;
  return 0;
}