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

const int MAX = 100010;
const int mod = 1e9 + 7;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

int powmod(int a, int b) {
  if (b == 0) return 1;
  if (b&1) return mul(a, powmod(a, b-1));
  return powmod(mul(a, a), b/2);
}

struct Edge {
  int b, w, c;
};

vector<Edge> E[MAX];
bool dead[MAX];
int bal[MAX];
int sz[MAX];
int ret = 1;

vector<int> v;

void dfs(int x, int dad) {
  v.push_back(x);
  sz[x] = 1;
  bal[x] = 0;
  for (Edge& e: E[x]) {
    int y = e.b;
    if (!dead[y] && y != dad) {
      dfs(y, x);
      sz[x] += sz[y];
      bal[x] = max(bal[x], sz[y]);
    }
  }
}

struct Path {
  int c0, c1, w;
};

void go(int x, int dad, int c0, int c1, int w, vector<Path>& paths) {
  paths.push_back({c0, c1, w});
  for (Edge& e: E[x]) {
    if (!dead[e.b] && e.b != dad) {
      go(e.b, x, c0 + (e.c == 0), c1 + (e.c == 1), mul(w, e.w), paths);
    }
  }
}

int countGoodPairs(vector<Path>& v) {
  if (v.size() == 0) return 1;
  
  int minv = v[0].c0;
  int maxv = v[0].c0;
  for (auto& p: v) {
    minv = min(minv, p.c0);
    maxv = max(maxv, p.c0);
  }

  int sz = maxv - minv + 10;
  vector<int> Lc(sz, 0), Lw(sz, 1);
  
  auto add = [&] (int x, int w) {
    x -= minv;
    for (++x; x < sz; x += x&-x) {
      Lc[x]++;
      Lw[x] = mul(Lw[x], w);
    }
  };

  auto sum = [&] (int x) {
    if (x > maxv) x = maxv;
    x -= minv;
    int w = 1, c = 0;
    for (++x; x > 0; x -= x&-x) {
      c += Lc[x];
      w = mul(w, Lw[x]);
    }
    return make_pair(w, c);
  };

  int ret = 1;
  REP(i, (int)v.size()) {
    auto others = sum(v[i].c1);
    ret = mul(ret, others.first);
    ret = mul(ret, powmod(v[i].w, others.second));
    add(v[i].c0, v[i].w);
  }
  return ret;
}

int countGoodPathPairs(vector<Path>& paths) {
  int ret = 1;
  vector<Path> v, w;
  REP(i, (int)paths.size()) {
    int c0 = paths[i].c0;
    int c1 = paths[i].c1;
    int we = paths[i].w;
    v.push_back({c1 - 2*c0, 2*c0 - c1, we});
    w.push_back({2*c1 - c0, c0 - 2*c1 - 1, we});
  }

  ret = mul(ret, countGoodPairs(v));
  ret = mul(ret, powmod(countGoodPairs(w), mod-2));
  return ret;
}

int solve(int x) {
  v.clear();
  dfs(x, -1);

  int m = -1;
  for (int y: v) {
    bal[y] = max(bal[y], sz[x] - sz[y]);
    if (m == -1 || bal[y] < bal[m]) m = y;
  }
  assert(m != -1 && 2*bal[m] <= sz[x]);

  x = m;
  dead[x] = true;
  int ret = 1;

  vector<Path> paths;
  go(m, -1, 0, 0, 1, paths);

  ret = mul(ret, countGoodPathPairs(paths));
  for (Edge& e: E[x]) {
    if (!dead[e.b]) {
      paths.clear();
      go(e.b, x, (e.c == 0), (e.c == 1), e.w, paths);
      ret = mul(ret, powmod(countGoodPathPairs(paths), mod-2));
    }
  }
  
  for (Edge& e: E[x])
    if (!dead[e.b]) ret = mul(ret, solve(e.b));
  return ret;
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n-1) {
    int a, b, w, c;
    scanf("%d %d %d %d", &a, &b, &w, &c);
    --a, --b;
    E[a].push_back({b, w, c});
    E[b].push_back({a, w, c});
  }

  int ret = solve(0);
  printf("%d\n", ret);
  
  return 0;
}