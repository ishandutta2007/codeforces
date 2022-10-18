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

const int off = 1<<17;
const int MAXN = 1<<17;
const int MAXMEM = 50*2*off;
const int mod = 1e9 + 7;

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int mul(int a, int b) {
  return (llint(a)*b)%mod;
}

int pw[MAXN];

struct Node {
  Node *l, *r;
  bool all0, all1;
  int hash;
  Node () {
    l = r = NULL;
    all0 = true, all1 = false;
    hash = 0;
  };
  void copy(Node *x) {
    l = x->l, r = x->r;
    all0 = x->all0, all1 = x->all1;
    hash = x->hash;
  };
  void update(int sz) {
    if (sz == 1) hash = all1; else {
      all0 = l->all0 && r->all0;
      all1 = l->all1 && r->all1;
      hash = add(mul(r->hash, pw[sz/2]), l->hash);
    }
  }
} mem[MAXMEM], *alloc = mem;

Node* build(int i) {
  Node *x = alloc++;
  if (i < off) {
    x->l = build(i*2);
    x->r = build(i*2+1);
  } 
  return x;
}

void propagate(Node *x) {
  if (x->all0 && !x->l->all0) {
    Node *nxl = alloc++;
    nxl->copy(x->l);
    nxl->all0 = true, nxl->all1 = false;
    nxl->hash = 0;
    x->l = nxl;
  }
  if (x->all0 && !x->r->all0) {
    Node *nxr = alloc++;
    nxr->copy(x);
    nxr->all0 = true, nxr->all1 = false;
    nxr->hash = 0;
    x->r = nxr;
  }
}

Node* addOne(Node *x, int sz, int k, bool &done) {
  Node* nx = alloc++;
  nx->copy(x);
  if (k == 0 && x->all1) {
    nx->all0 = true, nx->all1 = false;
    nx->hash = 0;
    return nx;
  }

  if (sz == 1) {
    swap(nx->all0, nx->all1);
    done = nx->all1;
    nx->update(sz);
    return nx;
  }
  
  propagate(nx);

  if (k < sz/2) {
    nx->l = addOne(nx->l, sz/2, k, done);
    k = sz/2;
  }
  k -= sz/2;
  if (!done) nx->r = addOne(nx->r, sz/2, k, done);
  nx->update(sz);
  return nx;
}

int compare(Node *x, Node *y) {
  if (x->hash == y->hash) return 0;
  if (x->all0 || y->all1) return 1;
  if (x->all1 || y->all0) return -1;
  int right = compare(x->r, y->r);
  if (right) return right;
  return compare(x->l, y->l);
}

struct Edge {
  int b, w;
};
vector<Edge> E[MAXN];
Node* D[MAXN];
bool bio[MAXN];
int dad[MAXN];

struct cmp {
  bool operator () (const int &a, const int &b) {
    int c = compare(D[a], D[b]);
    if (c) return c == 1;
    return a < b;
  }
};

set<int, cmp> S;

int main(void) {
  pw[0] = 1;
  FOR(i, 1, MAXN)
    pw[i] = mul(pw[i-1], 2);

  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, m) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c); --a, --b;
    E[a].push_back({b, c});
    E[b].push_back({a, c});
  }

  int s, t;
  scanf("%d %d", &s, &t); --s, --t;
  
  D[s] = build(1);
  S.insert(s);
  while (S.size()) {
    int x = *S.begin();
    S.erase(S.begin());
    bio[x] = true;

    if (x == t) {
      printf("%d\n", D[x]->hash);
      vector<int> ans;
      while (t != s) {
        ans.push_back(t);
        t = dad[t];
      }
      ans.push_back(s);
      reverse(ans.begin(), ans.end());
      printf("%d\n", (int)ans.size());
      for (int x: ans) printf("%d ", x+1);
      printf("\n");
      return 0;
    }

    for (Edge &e: E[x]) {
      int y = e.b, w = e.w;
      if (bio[y]) continue;

      bool done = false;
      Node* nd = addOne(D[x], off, w, done);

      assert(done);
      if (!D[y] || compare(nd, D[y]) == 1) {
        if (D[y]) S.erase(y);
        dad[y] = x;
        D[y] = nd;
        S.insert(y);
      }
    }
  }
  
  puts("-1");
  return 0;
}