#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;
typedef pair<int, int> par;

const int MAXN = 300010;
const int LG = 20;

const int H = 9973;

const int mod = 1e9 + 7;

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

int mul(int a, int b) {
  return (llint(a)*b)%mod;
}

int powmod(int a, int b) {
  if (b == 0) return 1;
  if (b&1) return mul(a, powmod(a, b-1));
  return powmod(mul(a, a), b/2);
}
int invH = powmod(H, mod-2);

int pw[MAXN], pwinv[MAXN];
int h[MAXN], hr[MAXN];

char s[MAXN];

vector<int> E[MAXN];
int L[LG][MAXN], dep[MAXN];

void dfs(int x, int dad) {
  L[0][x] = dad;
  REP(i, (int) E[x].size()) {
    int y = E[x][i];
    if (y != dad) {
      dep[y] = dep[x] + 1;
      h[y] = add(mul(h[x], H), s[y]);
      hr[y] = add(hr[x], mul(s[y], pw[dep[y]]));
      dfs(y, x);
    }
  }
}

int get_hash(int u, int v) {
  assert(dep[u] <= dep[v]);
  return sub(h[v], mul(h[u], pw[dep[v] - dep[u]]));
}

int get_hash_rev(int u, int v) {
  assert(dep[u] <= dep[v]);
  return mul(sub(hr[v], hr[u]), pwinv[dep[u]+1]);
}

int climb(int u, int d) {
  for (int i = LG-1; i >= 0; --i)
    if (d&(1<<i)) u = L[i][u];
  return u;
}

int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = LG-1; i >= 0; --i)
    if (dep[u]-(1<<i) >= dep[v]) u = L[i][u];
  if (u == v) return u;
  for (int i = LG-1; i >= 0; --i)
    if (L[i][u] != L[i][v]) u = L[i][u], v = L[i][v];
  return L[0][u];
}

int solve(int a, int b, int c, int d) {
  int lab = lca(a, b);
  int lcd = lca(c, d);
  int lenab = dep[a] + dep[b] - 2*dep[lab] + 1;
  int lencd = dep[c] + dep[d] - 2*dep[lcd] + 1;
  
  if (lenab > lencd) {
    swap(a, c);
    swap(b, d);
    swap(lab, lcd);
    swap(lenab, lencd);
  }
  
  int diff = lencd - lenab;
  if (diff > 0) {
    int upd = min(diff, dep[d] - dep[lcd]);
    d = climb(d, upd), lencd -= upd, diff -= upd;
    
    if (diff > 0) {
      lcd = d = climb(c, lencd-diff-1);
      lencd = dep[c] - dep[d] + 1;
      assert(lenab == lencd);
    }
  }

  if (dep[a] - dep[lab] < dep[c] - dep[lcd]) {
    swap(a, c);
    swap(b, d);
    swap(lab, lcd);
    swap(lenab, lencd);
  }
  
  int ans = 0;
  int p1 = dep[c] - dep[lcd];
  for (int i = LG-1; i >= 0; --i)
    if ((1<<i) <= p1)
      if (get_hash(L[i][c], c) == get_hash(L[i][a], a)) {
        ans += 1<<i, p1 -= 1<<i, lenab -= 1<<i, lencd -= 1<<i;
        c = L[i][c], a = L[i][a];
      }

  if (p1) return ans;

  
  assert(c == lcd);
  c = L[0][c];
  
  int p2 = dep[a] - dep[lab];
  if (p2 > 0) {
    int j = 0;
    while ((1<<(j+1)) <= p2) j++;

    int tmpd = d;
    int md = climb(d, dep[d] - dep[c] - p2);
    d = md;

    int nc = climb(d, dep[d] - dep[c] - (1<<j));
    if (get_hash(L[j][a], a) == get_hash_rev(c, nc)) {
      a = climb(a, p2 - (1<<j));
      c = L[j][d];
      ans += p2 - (1<<j);
      p2 = 1<<j;
    } else {
      b = lab = climb(a, 1<<j);
      d = nc;
      p2 = 1<<j;
    }
    
    for (int i = j-1; i >= 0; --i)
      if (get_hash(L[i][a], a) == get_hash_rev(c, L[i][d])) {
        ans += 1<<i, p2 -= 1<<i;
        c = L[i][d];
        a = L[i][a];
      } else {
        b = lab = L[i][a];
        d = L[i][d];
      }
    
    if (p2 == 1 && s[a] == s[d]) {
      p2--, ans++;
      a = L[0][a], d = L[0][d];
    }

    if (p2) return ans;
    
    c = md;
    d = tmpd;
  }

  a = L[0][lab];

  assert(dep[b] - dep[a] == dep[d] - dep[c]);
  int p3 = dep[b] - dep[a];
  if (p3 == 0) return ans;

  int j = 0;
  while ((1<<(j+1)) <= p3) j++;
  
  int na = climb(b, p3 - (1<<j));
  int nc = climb(d, p3 - (1<<j));
  if (get_hash(a, na) == get_hash(c, nc)) {
    a = L[j][b];
    c = L[j][d];
    ans += p3 - (1<<j);
    p3 = 1<<j;
  } else {
    b = na;
    d = nc;
    p3 = 1<<j;
  }

  for (int i = j-1; i >= 0; --i)
    if (get_hash(a, L[i][b]) == get_hash(c, L[i][d])) {
      ans += 1<<i, p3 -= 1<<i;
      c = L[i][d];
      a = L[i][b];
    } else {
      b = L[i][b];
      d = L[i][d];
    }
  
  if (p3 == 1 && s[b] == s[d]) p3--, ans++;
  return ans;
}

int main(void) {
  pw[0] = pwinv[0] = 1;
  FOR(i, 1, MAXN) {
    pw[i] = mul(pw[i-1], H);
    pwinv[i] = mul(pwinv[i-1], invH);
  }

  int n;
  scanf("%d", &n);
  scanf("%s", s+1);
  
  REP(i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b);
    E[a].push_back(b);
    E[b].push_back(a);
  }
  n++;
  
  dep[0] = h[0] = hr[0] = 0;
  E[0].push_back(1);
  dfs(0, 0);
  
  FOR(i, 1, LG) REP(u, n)
    L[i][u] = L[i-1][ L[i-1][u] ];
  
  int m;
  scanf("%d", &m);
  REP(i, m) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("%d\n", solve(a, b, c, d));
  }
  return 0;
}