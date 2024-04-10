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

const int MAXN = 200100;

vector<int> E[MAXN];
int parent[MAXN];
int sz[MAXN], bal[MAXN];
char a[MAXN];
llint ans[MAXN];
int mask[MAXN];
int cnt[1<<20];

vector<int> v;
int n;

void dfs(int x, int dad) {
  sz[x] = 1;
  bal[x] = 0;
  v.push_back(x);
  for (int y: E[x])
    if (y != dad) {
      mask[y] = mask[x] ^ (1 << (a[y] - 'a'));
      parent[y] = x;
      dfs(y, x);
      bal[x] = max(bal[x], sz[y]);
      sz[x] += sz[y];
    }
}

void add(int x, int k) {
  cnt[ mask[x] ] += k;
  for (int y: E[x]) {
    if (y != parent[x]) add(y, k);
  }
}

llint count(llint query_mask) {
  llint ret = cnt[query_mask];
  REP(k, 20) ret += cnt[query_mask ^ (1<<k)];
  return ret;
}

llint query(int y, int root_char) {
  llint ret = 0;
  ret += count(mask[y] ^ (1<<root_char));
  for (int z: E[y]) {
    if (z != parent[y]) {
      ret += query(z, root_char);
    }
  }

  ans[y] += ret;
  return ret;
}

void solve(int x, int prev) {
  REP(i, (int)E[x].size()) {
    if (E[x][i] == prev) {
      swap(E[x][i], E[x].back());
      E[x].pop_back();
      break;
    }
  }

  v.clear();
  dfs(x, -1);

  int m = -1;
  for (int x: v) {
    bal[x] = max(bal[x], (int)v.size()-sz[x]);
    if (m == -1 || bal[x] < bal[m]) m = x;
  }
  x = m;

  v.clear();

  parent[x] = -1;
  mask[x] = 0;
  dfs(x, -1);

  add(x, +1);

  int root_char = a[x] - 'a';
  llint add_x = count(1 << root_char);

  for (int y: E[x]) {
    add(y, -1);
    add_x += query(y, root_char);
    add(y, +1);
  }

  ans[x] += add_x / 2 + 1;
  add(x, -1);

  for (int y: E[x]) {
    solve(y, x);
  }
}

int main(void) {
  scanf("%d", &n);
  REP(i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  scanf("%s", a);

  solve(0, -1);

  REP(i, n) printf("%lld ", ans[i]);
  puts("");
  return 0;
}