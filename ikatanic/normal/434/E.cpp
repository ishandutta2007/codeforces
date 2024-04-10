#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 100100;

int pw[MAXN], inv[MAXN];
int mod, xmod, k;

int add(int x, int y) {
  return x+y >= mod ? x+y-mod : x+y;
}
int sub(int x, int y) {
  return x >= y ? x-y : x-y+mod;
}
int mul(int x, int y) {
  return (llint(x)*y)%mod;
}

int powmod(int a, int b) {
  if (b == 0) return 1;
  if (b&1) return mul(a, powmod(a, b-1));
  return powmod(mul(a, a), b/2);
}

typedef pair<int, int> par;
#define id first
#define off second

struct data {
  map<int, vector<par>> V;
  map<int, int> M;
  int p, a;
  
  int eval(int x) { return add(mul(x, pw[p]), a); }
  int rev(int x) { return mul(sub(x, a), inv[p]); }  
  void mulK(int d) {
    p += d;
    if (d < 0) a = mul(a, inv[-d]); else
      a = mul(a, pw[d]);
  }
  void addA(int d) {
    if (d < 0) a = sub(a, -d); else
      a = add(a, d);
  }
  
  void insert(int x, int id, int d) {
    x = rev(x);
    if (!M.count(x)) {
      M[x] = 0;
      V[x] = vector<par>();
    }
    V[x].push_back({id, d-M[x]});
  }
  
  int count(int x, int d) {
    x = rev(x);
    if (!M.count(x)) return 0;
    M[x] += d;
    return V[x].size();
  }

  void clear(int *in) {
    for (auto &v: V) {
      int cnt = M[v.first];
      for (auto &p: v.second)
        in[p.id] += cnt + p.off;
    }
    p = a = 0;
    M.clear();
    V.clear();
  }
} mem[MAXN];
data *alloc = mem;

data *d[MAXN];
int val[MAXN];
int in[MAXN], out[MAXN];
int sz[MAXN], m[MAXN];
vector<int> E[MAXN];

void dfs(int x, int dad) {
  m[x] = -1, sz[x] = 1;
  for (int y: E[x])
    if (y != dad) {
      dfs(y, x);
      sz[x] += sz[y];
      if (m[x] == -1 || sz[y] > sz[m[x]]) m[x] = y;
    }
  if (dad != -1) E[x].erase(find(E[x].begin(), E[x].end(), dad));
  if (m[x] != -1) E[x].erase(find(E[x].begin(), E[x].end(), m[x]));
}

void go(int x, data *good, data *bad) {
  good->mulK(+1), good->addA(+val[x]);
  bad->mulK(+1), bad->addA(+val[x]);

  out[x] += good->count(xmod, +1);
  out[x] -= bad->count(xmod, -1);

  for (int y: E[x]) go(y, good, bad);
  if (m[x] != -1) go(m[x], good, bad);

  good->addA(-val[x]), good->mulK(-1);
  bad->addA(-val[x]), bad->mulK(-1);
}
  
void solveDown(int x) {
  if (m[x] == -1) d[x] = alloc++; else {
    solveDown(m[x]);
    d[x] = d[m[x]];
  }

  d[x]->mulK(1);
  d[x]->insert(0, x, 0);
  d[x]->addA(val[x]);

  for (int y: E[x]) {
    solveDown(y);
    d[y]->mulK(1), d[y]->addA(val[x]);
    for (auto &v: d[y]->V) {
      int real_v = d[y]->eval(v.first);
      for (auto &p: v.second)
        d[x]->insert(real_v, p.id, 0);
    }
  }
  
  for (int y: E[x]) { 
    go(y, d[x], d[y]);
    d[y]->clear(in);
  }

  out[x] += d[x]->count(xmod, +1);
}

void fill(int x, int cur, int len, data *d) {
  cur = add(cur, mul(val[x], pw[len]));
  d->insert(cur, x, 0);
  for (int y: E[x])
    fill(y, cur, len+1, d);
  if (m[x] != -1) fill(m[x], cur, len+1, d);
}

void solveUp(int x) {
  d[x]->mulK(1), d[x]->addA(val[x]);
  for (int y: E[x]) {
    d[y] = alloc++; // prazno
    go(y, d[x], d[y]);
    solveUp(y);
    d[y]->clear(in);
  }

  out[x] += d[x]->count(xmod, +1);  
  d[x]->insert(val[x], x, 0);

  if (m[x] != -1) {
    for (int y: E[x])
      fill(y, val[x], 1, d[x]);
    d[m[x]] = d[x];
    solveUp(m[x]);
  }
}

int main(void) {
  int n;
  scanf("%d %d %d %d", &n, &mod, &k, &xmod);
  REP(i, n) scanf("%d", val+i);
  REP(i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  pw[0] = inv[0] = 1;
  REP(i, n) {
    pw[i+1] = mul(pw[i], k);
    inv[i+1] = powmod(pw[i+1], mod-2);
  }

  dfs(0, -1);

  solveDown(0);
  d[0]->clear(in); alloc = mem;
  
  d[0] = alloc++;
  solveUp(0);
  d[0]->clear(in); alloc = mem;

  llint bad = 0;
  REP(i, n) {
    llint in1 = in[i], in0 = n - in[i];
    llint out1 = out[i], out0 = n - out[i];
    bad += 2*in1*in0 + in1*out0 + 2*out1*out0 + out1*in0;
  }

  llint ans = llint(n)*n*n - bad/2;
  cout << ans << endl;
  return 0;
}