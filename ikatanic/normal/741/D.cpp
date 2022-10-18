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

const int MAX = 500500;
const int S = 22;
const int inf = 1e9;

int p[MAX];
int c[MAX];

int best[1<<S];
int off_xor;
int off_add;
vector<int> E[MAX];

int ans[MAX];
int sz[MAX];

void chmax(int ms, int len, int& ans) {
  ans = max(ans, off_add + best[ms ^ off_xor] + len);
  REP(i, S) ans = max(ans, off_add + best[ms ^ off_xor ^ (1<<i)] + len);
}

void chupd(int ms, int len) {
  best[ms ^ off_xor] = max(best[ms ^ off_xor], len - off_add);
}


void go_max(int x, int ms, int len, int& ans) {
  chmax(ms, len, ans);
  for (int y: E[x])
    go_max(y, ms ^ (1<<c[y]), len + 1, ans);
}

void go_upd(int x, int ms, int len) {
  chupd(ms, len);
  for (int y: E[x])
    go_upd(y, ms ^ (1<<c[y]), len + 1);
}

void go_clean(int x, int ms) {
  best[ms ^ off_xor] = -inf;
  for (int y: E[x])
    go_clean(y, ms ^ (1<<c[y]));
}

void dfs(int x, bool keep = false) {
  int m = -1;
  for (int y: E[x])
    if (m == -1 || sz[y] > sz[m]) m = y;

  for (int y: E[x])
    if (y != m) dfs(y, false);

  if (m != -1) {
    dfs(m, true);
    off_xor ^= 1 << c[m];
    off_add++;
    ans[x] = max(ans[x], ans[m]);
  }

  chmax(0, 0, ans[x]);
  chupd(0, 0);
  
  for (int y: E[x])
    if (y != m) {
      go_max(y, 1 << c[y], 1, ans[x]);
      go_upd(y, 1 << c[y], 1);
      ans[x] = max(ans[x], ans[y]);
    }

  if (!keep) {
    go_clean(x, 0);
    off_xor = off_add = 0;
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  FOR(i, 1, n) {
    static char s[5];
    scanf("%d %s", &p[i], s);
    p[i]--;
    c[i] = s[0] - 'a';
    E[p[i]].push_back(i);
  }

  for (int i = n-1; i > 0; --i) {
    sz[i]++;
    sz[p[i]] += sz[i];
  }

  REP(i, 1<<S) best[i] = -inf;
  dfs(0);

  REP(i, n) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}