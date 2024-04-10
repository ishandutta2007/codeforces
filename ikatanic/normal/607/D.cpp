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

const int MAXN = 200100;
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

struct data {
  int a, b;
};

data operator + (const data &l, const data &r) {
  return {add(l.a, mul(l.b, r.a)), mul(l.b, r.b)};
}

vector<int> E[MAXN];
int sum[MAXN], deg[MAXN], pw[MAXN], alive[MAXN];

struct HeavyPath {
  vector<int> v;  
  vector<data> T;
  int off, n, last;

  void init() {
    n = (int)v.size();
    for (off = 1; off < n; off *= 2);
    T.resize(2*off, {0, 0});
  }
  
  data query(int i, int lo, int hi, int a, int b) {
    if (lo >= b || hi <= a) return {0, 1};
    if (lo >= a && hi <= b) return T[i];
    return 
      query(i*2, lo, (lo+hi)/2, a, b) +
      query(i*2+1, (lo+hi)/2, hi, a, b);
  }

  int calc(int x) {
    data q = query(1, 0, off, x, last);
    return add(q.a, mul(q.b, pw[v[last]]));
  }

  void update(int x) {
    if (!alive[v[x]]) last = x;

    T[off + x] = {mul(sum[v[x]], deg[v[x]] + 1), deg[v[x]] + 1};
    pw[v[x]] = mul(sum[v[x]], deg[v[x]]);
    alive[v[x]] = 1;

    for (x = (x + off)/2; x; x /= 2)
      T[x] = T[x*2] + T[x*2+1];

    pw[v[0]] = calc(0);
  }
};

HeavyPath H[MAXN];
int c;

int d[MAXN], parent[MAXN], sz[MAXN];
int ch_id[MAXN], ch_pos[MAXN]; // koji heavy path i koja pozicija u njemu

int v[MAXN], dad[MAXN];
int qt[MAXN], qu[MAXN];

void dfs(int x, int dad) {
  parent[x] = dad;
  sz[x] = 1;
  for (int y: E[x])
    if (y != dad) {
      d[y] = d[x] + 1;
      dfs(y, x);
      sz[x] += sz[y];
    }
}

void decompose(int x, int id, int pos) {
  ch_id[x] = id, ch_pos[x] = pos;
  H[id].v.push_back(x);

  int m = -1;
  for (int y: E[x])
    if (y != parent[x])
      if (m == -1 || sz[y] > sz[m]) m = y;
  
  if (m == -1) return;

  decompose(m, id, pos + 1);
  for (int y: E[x])
    if (y != parent[x] && y != m) decompose(y, c++, 0);
}

void update(int x) {
  sum[x] = v[x];
  deg[x] = 1;
  while (x != -1) {
    int root = H[ch_id[x]].v[0];
    if (dad[root] != -1) {
      int par = dad[root];
      sum[par] = sub(sum[par], pw[root]);
      deg[par] = sub(deg[par], alive[root]);
    }

    H[ch_id[x]].update(ch_pos[x]);

    if (dad[root] != -1) {
      int par = dad[root];
      sum[par] = add(sum[par], pw[root]);
      deg[par] = add(deg[par], alive[root]);
    }
    x = dad[root];
  }
}

int query(int x) {
  return H[ch_id[x]].calc(ch_pos[x]);
}

int main(void) {
  int v0, q;
  scanf("%d %d", &v0, &q);

  int n = 0;
  dad[n] = -1;
  v[n++] = v0;
  REP(i, q) {
    scanf("%d", &qt[i]);
    if (qt[i] == 1) {
      int qp, qv;
      scanf("%d %d", &qp, &qv); --qp;
      qu[i] = n;
      dad[n] = qp;
      E[qp].push_back(n);
      v[n++] = qv;
    }
    if (qt[i] == 2) {
      scanf("%d", &qu[i]); --qu[i];
    }
  }

  dfs(0, -1);
  decompose(0, c++, 0);
  REP(i, c) H[i].init();

  update(0);
  //  TRACE(query(0));

  REP(i, q) {
    if (qt[i] == 1) update(qu[i]);
    if (qt[i] == 2) printf("%d\n", query(qu[i]));
  }
  return 0;
}