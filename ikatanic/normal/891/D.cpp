#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

struct Sol {
  llint f00, f01, f10, f11;

  static Sol OneNode() {
    return {0, 1, 1, 0};
  }

  static Sol Empty() {
    return {1, 0, 0, 0};
  }

  static Sol AddRoot(const Sol& a) {
    return {a.f01, a.f00, a.f00 + a.f11, a.f10};
  }

  friend Sol operator + (const Sol& a, const Sol& b) {
    llint f00 = a.f00 * b.f00;
    llint f01 = a.f00 * b.f01 + a.f01 * b.f00;
    llint f10 = a.f10 * b.f00 + a.f00 * b.f10;
    llint f11 = a.f10 * b.f01 + a.f01 * b.f10 + a.f00 * b.f11 + a.f11 * b.f00;
    return {f00, f01, f10, f11};
  }
};

const int MAX = 500500;

vector<int> E[MAX];
Sol f_down[MAX];
Sol f_up[MAX];
int sz[MAX];

void DfsDown(int x, int dad) {
  f_down[x] = Sol::Empty();
  sz[x] = 1;
  for (int y: E[x]) {
    if (y != dad) {
      DfsDown(y, x);
      f_down[x] = f_down[x] + f_down[y];
      sz[x] += sz[y];
    }
  }
  f_down[x] = Sol::AddRoot(f_down[x]);
}

void DfsUp(int x, int dad) {
  REP(i, (int)E[x].size()) {
    if (E[x][i] == dad) {
      E[x].erase(E[x].begin() + i);
      break;
    }
  }

  vector<Sol> pre = {Sol::Empty()};
  for (int y: E[x]) {
    Sol pre_y = pre.back() + f_down[y];
    pre.push_back(pre_y);
  }

  vector<Sol> suf = {Sol::Empty()};
  for (int i = (int)E[x].size() - 1; i >= 0; --i) {
    Sol suf_y = suf.back() + f_down[E[x][i]];
    suf.push_back(suf_y);
  }

  for (int i = 0; i < (int)E[x].size(); ++i) {
    int y = E[x][i];
    f_up[y] = Sol::AddRoot(f_up[x] + pre[i] + suf[(int)E[x].size() - i - 1]);
  }

  for (int y: E[x]) {
    DfsUp(y, x);
  }
}

int main(void) {
  int n;
  scanf("%d", &n);

  if (n % 2) {
    puts("0");
    return 0;
  }

  REP(i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  DfsDown(0, -1);
  f_up[0] = Sol::Empty();
  DfsUp(0, -1);
  llint ans = 0;
  FOR(i, 1, n) {
    if (sz[i] % 2 == 0) {
      ans += f_down[i].f00 * f_up[i].f00 * sz[i] * (n - sz[i]);
    } else {
      ans += f_down[i].f10 * f_up[i].f10;
    }
  }

  printf("%lld\n", ans);
  return 0;
}